/* Returning amount of the most frequent character in text (Возвращает количество самого частого символа в тексте) */
int most_common(int frequency[ASCII_END], int call) {
  int max = frequency[1];
  for(int i = ASCII_START; i < ASCII_END; i++) {
    if(frequency[i] > max && !already_checked(i)){
      max = frequency[i];
      top_five_symbols[call] = i;
    }
  }
  return max;
}

int already_checked(int N) {
  for(int i = 0; i < 5; i++) {
    if( N == top_five_symbols[i] ) {
      return 1;
    }
  }
  return 0;
}  
/* Сount how many characters are in the text, write it into the dictionary of entries
 (Считаем сколько символов в тексте, записываем в словарь вхождений)
  @param stream pointer to file with text (указатель на файл с текстом)
*/
void count_symbols(FILE *stream) {
  while (!feof(stream)) {
    char tmp = fgetc(stream);
    if( ASCII_START <= tmp && tmp <= ASCII_END ) {
      text_length++;
      frequency[tolower(tmp)] ++;
    }
  }
}

/* Function for output(Функция для вывода)
  @param start @param fin - from which number to display characters (с какого по какое число выводить символы)
*/
void output(int start, int fin) {
  for (int i = start; i < fin; i++) {
    if (frequency[i]) {
      printf("Символ ");
      printf("%c", i);
      printf(" : ");
      printf("%f", get_percent(frequency[i]));
      printf("%c\n", '%');
    }
  }
  printf("\n");
}

float get_percent(int num) {
  return (float) num / text_length * 100;
}


/* Function for displaying info about the frequency of occurrence of a given type of characters (Функция для вывода инфы о частоте встречи заданого типа символов)
  @param command - Command - type of checked symbols(команда - тип проверяемых символов)
*/
void symbols_freq(char command) {
  if (command == 'e') { //english letters(англ буквы)
    output('a', 'z'+1);
  } else if (command == 's') { //non-alphabetical symbols(небукв. символы)
    output(ASCII_START, 'a');
    output('z'+1, ASCII_END);
  } else if ( command == 'r') { //russian letters(русские буквы)
    printf("Russian language is not avaliable");
  } else { //Invalid command(неправильная комманда)
    printf("Invalid input");
  }
} 

char * convert(char * s, int numRows){
  if (numRows == 1) {
    return s;
  }
  
  int len = strlen(s);  
  int cycle = numRows * 2 - 2;
  char* res = malloc(sizeof(char) * (len + 1));
  memset(res, '\0', sizeof(char) * (len + 1));

  int index = 0, j = 0, step;
  for (int i = 0; i < numRows; i++) {
    j = i;
    step = cycle - 2 * i;
    while (j < len) {
      res[index++] = s[j];
      if (!((i == 0) || i == (numRows - 1))) {
        if (j + step < len) {
          res[index++] = s[j + step];
        }
      }
      j += cycle;
    }
  }  

  return res;
}

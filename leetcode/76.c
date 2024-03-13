
char* minWindow(char* s, char* t) {
  int left = 0, right = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    for( int j=0;t[j]!='\0';j++){
        if (s[i]==t[j]) {
            right++;
        }
    }
  }
}
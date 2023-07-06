int lengthOfLongestSubstring(char * s){
    int max = 0, left = -1;
    int* map = (int*) malloc(sizeof(int) * 256);
    memset(map, 0, sizeof(int) * 256);

    int start = 0, end = 0;
    while(s[end] != '\0') {
        if (map[s[end]] > 0) {
            if (max < end - start) {
                max = end - start;
            }
            map[s[start]]--;
            start++;
        } else {
            map[s[end]]++;
            end++;
        }
    }

    if (max < end - start) {
        max = end - start;
    }

    return max;
  
}

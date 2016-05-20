char* reverseString(char* s) {
	if (s == NULL) {
		return NULL;
	}

	char* pChar = &(s[0]);
	int charCount = 0;
	while (*pChar != '\0') {
		charCount++;
		pChar++;
	}

	pChar = (char*) malloc(sizeof(char) * (charCount + 1));

	for (int i = 0; i < charCount; i++) {
		pChar[i] = s[(charCount -1) - i];
	}
	pChar[charCount] = '\0';

	return pChar;
}

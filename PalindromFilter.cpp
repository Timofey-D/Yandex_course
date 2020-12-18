bool IsPalindrom(string str) {
        for (int i = 0; i < str.size() / 2; i++) {
                if (str[i] != str[str.size() - 1 - i])
                        return false;
        }
        return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string> result;
    	for (int i = 0; i < words.size(); i++) {
        	if ( IsPalindrom(words[i]) && words[i].size() >= minLength)
			result.push_back(words[i]); 
    	}
    	return result;
}

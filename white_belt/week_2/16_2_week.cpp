set<string> BuildMapValuesSet(const map<int, string>& m) {
	set<string> result;

	for (auto & [key, value] : m) {

		result.insert(value);
	
	}

	return result;
}

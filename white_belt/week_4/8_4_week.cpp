void EnsureEqual(const std::string& left, const std::string& right)
{
	std::string error_message;
	if (left != right)
	{
		error_message += left + " != " + right;
		throw std::runtime_error(error_message);
	}
}

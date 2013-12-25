BigInt operator+(const BigInt &lhs, const BigInt &rhs)
{
	return lhs.add(rhs);
}

BigInt operator-(const BigInt &lhs, const BigInt &rhs)
{
	return lhs.sub(rhs);
}

BigInt operator*(const BigInt &lhs, const BigInt &rhs)
{
	return lhs.mult(rhs);
}


BigInt BigInt::mult(const BigInt &rhs)
{
	const std::string 
		  &longer = _digits.size() > rhs._digits.size() ? _digits : rhs._digits;
		, &shorter = &longer == &_digits ? rhs._digits : _digits;
	BigInt result("0");
	bool carry = false;
	int x, i = 0;
	std::string prod;
	std::string::iterator p_it;
	
	for ( std::string::const_reverse_iterators s_it = shorter.size()
	    ; s_it != shorter.rend()
	    ; s_it++, i++) {
		prod = string(longer.size() + 1, '0');
		p_it = prod.rbegin();
		for ( std::string::const_reverse_iterator l_it = longer.rbegin()
		    ; l_it != longer.rend()
		    ; l_it++, p_it++) {
			x = ((*l_it - '0') * (*s_it - '0')) + carry;
			carry = x > 9;
			*p_it = x % 10;
		}
		result += BigInt(prod);
	}
		
		
	return result;
}

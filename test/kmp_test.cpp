#include <gtest/gtest.h>

#include <kmp.hpp>

#include <iostream>
#include <string>

using namespace cust;

template <class T>
std::ostream& operator<<(std::ostream& os, std::vector<T> const& v) {
    for (auto const& e : v) {
        os << e << ", ";
    }
    return os << std::endl;
}

std::string stringExample1() {
	return "abcabca";
}

TEST(ZFunction, TestOnStringExample1) {
	auto stringExample = stringExample1();
	std::vector<size_t> expected {
		7, 0, 0, 4, 0, 0, 1
	};

	auto z = z_function(stringExample);

	ASSERT_EQ(z, expected);
}

TEST(StrongPrefixFunciton, TestOnStringExample1) {
	auto stringExample = stringExample1();
	std::vector<size_t> expected {
		0, 0, 0, 0, 0, 0, 4
	};

	auto spf = strongPrefixFunction(stringExample);

	ASSERT_EQ(spf, expected);
}

std::tuple<std::string, std::string> kmpAlgoExample1() {
	return std::make_tuple<std::string, std::string>(
		"acbb",
		"abaacbbacbb"
	);
}

TEST(KnuthMorrisPrattAlgorithm, TestOnExample1) {
	std::string pattern, text;
	std::tie(pattern, text) = kmpAlgoExample1();

	std::vector<size_t> expected {
		3, 7
	};

	auto result = knuthMorrisPrattAlgorithm(pattern, text);

	ASSERT_EQ(result, expected);
}

std::tuple<std::string, std::string> kmpAlgoExample2() {
	return std::make_tuple<std::string, std::string>(
		"AABA",
		"AABAACAADAABAABA"
	);
}

TEST(KnuthMorrisPrattAlgorithm, TestOnExample2) {
	std::string pattern, text;
	std::tie(pattern, text) = kmpAlgoExample2();

	std::vector<size_t> expected {
		0, 9, 12
	};

	auto result = knuthMorrisPrattAlgorithm(pattern, text);

	ASSERT_EQ(result, expected);
}


std::tuple<std::string, std::string> kmpAlgoExample3() {
	return std::make_tuple<std::string, std::string>(
		"abcabdabc",
		"abcabcabdabdabcabdabcabd"
	);
}

TEST(KnuthMorrisPrattAlgorithm, TestOnExample3) {
	std::string pattern, text;
	std::tie(pattern, text) = kmpAlgoExample3();

	std::vector<size_t> expected {
		12
	};

	auto result = knuthMorrisPrattAlgorithm(pattern, text);

	ASSERT_EQ(result, expected);
}

int main(int argc, char **argv)
{
  	::testing::InitGoogleTest(&argc, argv);
  
	return RUN_ALL_TESTS();
}
//Copyright 2019 Shantam Bajpai
/**
 *
 * @file  func.hpp
 * @brief A header file defining the function named read_words to input a stream of words
 * @author  Shantam Bajpai
 * @date  8th September 2019
 * @version 1.0
 *
 */

/*Define to prevent recursive inclusion*/
#pragma once
#ifndef GUARD_lib_h
#define GUARD_lib_h

/*Includes.............*/

#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstdio>

using namespace std;

/*Functions..............*/
istream &read_words(istream &, vector<string> &);
int words_input(const vector<string> &);

/**
 * @brief function to input a stream of words in a vector
 * @param input: To input the words
 * @param words: A vector to store the words
 * @retval  Returns the input
 */

istream & read_words(istream &input, std::vector<string> & words) {
  if (input) {
    string s;
    while (input >> s)
      words.push_back(s);
    input.clear();
  }
  return input;
}

/**
 * @brief Function to count the number of words in the stream and print the words
 * @param words:const reference to vector of input strings
 * @retval  Returns the number of words in the stream
 */

int words_input(const std::vector<string> & words) {
  std::sort(words.begin(), words.end());
  for (vector<string>::size_type i = 0; i != words.size(); i++) {
    std::cout << "The words in the input stream are: " << std::endl;
    std::cout << words[i] << std::endl;
  }
  std::cout << "The total words in the input stream are :" << words.size();
  return 0;
}

/**
 * @brief Function to count the occurence of a specefic word in the stream
 * @param words:const reference to vector of input strings
 * @retval  Returns the word and the number of times it occured
 */
/*int words_occurence(const std::vector<string> & words) {
 int count = 0;
 sort(words.begin(), words.end());
 std::vector<string>::iterator it;
 std::map<string, int> mymap;


 }
 }*/

#endif






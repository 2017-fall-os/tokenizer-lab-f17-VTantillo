Name: Victor Tantillo

# Tokenizer
For my implementation of the tokenizer, I do not have an option to specify another character to delimit by.  The only bug that I have found is that if the user types in an extra space in the "main" program, it prints it at the end of the output.  I don't think this is a bug with the tokenizer itself, but with how I am printing the output at the end of the loop.

## Use
When you run 'make', two executable files are created.
1. test: Runs the test cases that were provided in the assignment description to make sure the tokenizer is running as intended.  To check that it passes, it compares the number of words that should be counted, to the number of words that are counted.  Then it prints out the vector with each token being on it's own line.
2. main: Runs a program that allows the user to input their own string to be tokenized.  It runs the tokenizer on that string and prints each token to it's own line.  Then the loop repeats until the user types in "quit".  

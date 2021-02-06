
void test_binary_search() {
  int input[4] = {-2, -1, 4, 98};
  
  int expected = 4;
  int result = binary_search(4, input, 4);
  cout << "expected: " << expected << ", result: " << result << endl; 
}

void test_is_sorted(int *input, int N) {
  for (int i = 0; i < N; i++)
  {
    cout << input[i] << " ";
  }
  cout << endl;
}

void test(int N, int* input, int expected) {
  int result = get_answer(N, input);
  (result == expected) ? cout << "[SUCCESS] " : cout << "[FAILURE] ";
  cout << "expected: " << expected << ", result: " << result << endl; 
}

// void test1()
// {
//   test(5, {98, -2, -1, 97, 100}, -3);

// }
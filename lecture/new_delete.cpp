/* new 와 delete 의 사용 */
#include <iostream>

/*
int main() {
  int* p = new int;
  *p = 10;

  std::cout << *p << std::endl;

  delete p;
  return 0;
}

*/

/* new 로 배열 할당하기 */
#include <iostream>

int main()
{
	int	arr_size;
	
	std::cout << "array size : ";
	std::cin >> arr_size;
	
	int	*arr = new int[arr_size];
	for (int i = 0; i < arr_size; i++)
	{
		std::cin >> arr[i];
	}
	for (int i = 0; i < arr_size; i++)
	{
		std::cout << i << "th element of arr : " << arr[i] << std::endl;
	}
	delete[] arr;
	return 0;
}
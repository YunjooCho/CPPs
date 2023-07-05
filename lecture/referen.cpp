/* 출력하기 */

#include <iostream>

/*

int main() {
  int a = 3;
  int& another_a = a;

  another_a = 5;
  std::cout << "a : " << a << std::endl;
  std::cout << "another_a : " << another_a << std::endl;

  return 0;
}

int main()
{
	// 1. 별도 변수로 값 초기화 
	// int	value = 11;
	// int	*num = &value;

	//2. 포인터를 통해 값 초기화
	int	*num;
	*num = 11;

	//3. 레퍼런스 선언 및 초기화
	int	*&referen_num = num;

	//4. 값 확인
	std::cout << "*num : " << *num << std::endl;
	std::cout << "num : " << num << std::endl;
	// std::cout << "&value : " << &value << std::endl;
	std::cout << "referen_num : " << referen_num << std::endl;

	std::cout << std::endl;

	//5. cin이 scanf()에서처럼 변수에 &를 사용하지 않고도 변수에서 값을 출력할 수 있는 이유
	int user_input = 111;
	int& referen_cin = user_input;

	std::cout << "user_input : " << user_input << std::endl;

	return 0;
}

*/

int& function() {
  int a = 2;
  return a;
}

int main() {
  int b = function();
  b = 3;
  return 0;
}
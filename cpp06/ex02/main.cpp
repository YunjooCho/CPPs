/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:29:37 by yunjcho           #+#    #+#             */
/*   Updated: 2023/11/30 20:41:02 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base *generate(void) {
  int rand;

  rand = std::rand() % 3;
  if (rand == 0) {
    std::cout << "Make : A" << std::endl;
    return (new A());
  } else if (rand == 1) {
    std::cout << "Make : B" << std::endl;
    return (new B());
  } else if (rand == 2) {
    std::cout << "Make : C" << std::endl;
    return (new C());
  } else {
    std::cout << rand << std::endl;
  }
  return (NULL);
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p) != NULL) {
    std::cout << "Pointer : A" << std::endl;
  } else if (dynamic_cast<B *>(p) != NULL) {
    std::cout << "Pointer : B" << std::endl;
  } else if (dynamic_cast<C *>(p) != NULL) {
    std::cout << "Pointer : C" << std::endl;
  } else {
    std::cout << "Pointer : Error" << std::endl;
  }
}

void identify(Base &p) {
  try {
    static_cast<void>(dynamic_cast<A &>(p));
    std::cout << "Reference : A" << std::endl;
  } catch (const std::exception &e)  // const std::bad_cast&
  {
  }
  try {
    static_cast<void>(dynamic_cast<B &>(p));
    std::cout << "Reference : B" << std::endl;
  } catch (const std::exception &e) {
  }
  try {
    static_cast<void>(dynamic_cast<C &>(p));
    std::cout << "Reference : C" << std::endl;
  } catch (const std::exception &e) {
  }
}

int main(void) {
  Base *newInstance;
  std::srand(static_cast<unsigned int>(time(NULL)));

  for (int i = 0; i < 100; i++) {
    std::cout << i + 1 << std::endl;
    newInstance = generate();
    identify(newInstance);
    identify(*newInstance);
    std::cout << std::endl;
    delete newInstance;
  }
  return (0);
}

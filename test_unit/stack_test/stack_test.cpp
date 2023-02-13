/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:54:02 by achane-l          #+#    #+#             */
/*   Updated: 2023/02/13 14:58:27 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include "../../container/stack.hpp"
#include <assert.h>
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define END "\033[0m"

#define CYAN "\033[1;36m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define WHITE "\033[1;37m"

#define GREY "\033[1;90m"

#ifndef lib_used
    #define lib_used ft
    #define lib_used2 std
#elif lib_used==ft
    #define lib_used2 std
#elif lib_used==std
    #define lib_used2 ft
#endif

template <typename T>
static void test_default_constructor()
{
    lib_used::stack<T> a;
    lib_used2::stack<T> b;

    assert(a.empty());
    assert(b.empty());

    a.push(T());
    b.push(T());

    assert(a.size());
    assert(b.size());

    a.pop();
    b.pop();

    assert(a.empty());
    assert(b.empty());
}

static void default_constuctor()
{
    test_default_constructor<int>();
    test_default_constructor<float>();
    test_default_constructor<char>();
    test_default_constructor<char *>();
    test_default_constructor<std::string>();

    std::cout << CYAN "default_constructor: " << GREEN "OK" END << std::endl;
}

template <typename T>
static void test_empty()
{
    lib_used::stack<T> a;
    lib_used2::stack<T> b;

    assert(a.empty());
    assert(b.empty());

    a.push(T());
    b.push(T());

    assert(!a.empty());
    assert(!b.empty());

    a.pop();
    b.pop();

    assert(a.empty());
    assert(b.empty());
}

static void empty()
{
    test_empty<int>();
    test_empty<float>();
    test_empty<char>();
    test_empty<char *>();
    test_empty<std::string>();

    std::cout << CYAN "empty: " << GREEN "OK" END << std::endl;
}

template <typename T>
static void test_size()
{
    lib_used::stack<T> a;
    lib_used2::stack<T> b;

    assert(a.empty());
    assert(b.empty());

    for (size_t i = 0; i < 50; i++)
    {
        assert(a.size() == i);
        assert(b.size() == i);
        a.push(T());
        b.push(T());
    }

    assert(a.size() == 50);
    assert(b.size() == 50);

    a.pop();
    b.pop();

    assert(a.size() == 49);
    assert(b.size() == 49);
}

static void size()
{
    test_size<int>();
    test_size<float>();
    test_size<char>();
    test_size<char *>();
    test_size<std::string>();

    std::cout << CYAN "size: " << GREEN "OK" END << std::endl;
}

static void test_top_practical()
{
    lib_used::stack<int> a;
    lib_used2::stack<int> b;

    for (int i = 0; i < 50; i++)
    {
        a.push(i);
        b.push(i);
        assert(a.top() == i);
        assert(b.top() == i);
    }
}

template <typename T>
static void test_top()
{
    lib_used::stack<T> a;
    lib_used2::stack<T> b;

    a.push(T());
    b.push(T());

    assert(a.top() == T());
    assert(b.top() == T());
}

static void top()
{
    test_top_practical();
    test_top<int>();
    test_top<float>();
    test_top<char>();
    test_top<char *>();
    test_top<std::string>();

    std::cout << CYAN "top: " << GREEN "OK" END << std::endl;
}

template <typename T>
static void test_push()
{
    lib_used::stack<T> a;
    lib_used2::stack<T> b;

    for (size_t i = 0; i < 50; i++)
    {
        assert(a.size() == i);
        assert(b.size() == i);
        a.push(T());
        b.push(T());
    }

    a.pop();
    assert(a.size() == 49);
    a.push(T());
    assert(a.size() == 50);

    b.pop();
    assert(b.size() == 49);
    b.push(T());
    assert(b.size() == 50);
}

static void push()
{
    test_push<int>();
    test_push<float>();
    test_push<char>();
    test_push<char *>();
    test_push<std::string>();

    std::cout << CYAN "push: " << GREEN "OK" END << std::endl;
}

template <typename T>
static void test_pop()
{
    lib_used::stack<T> a;
    lib_used2::stack<T> b;

    for (size_t i = 0; i < 50; i++)
    {
        a.push(T());
        b.push(T());
    }

    for (size_t i = 0; i < 50; i++)
    {
        assert(a.size() == 50 - i);
        assert(b.size() == 50 - i);
        a.pop();
        b.pop();
    }
    assert(a.empty());
    assert(b.empty());
}

static void pop()
{
    test_pop<int>();
    test_pop<float>();
    test_pop<char>();
    test_pop<char *>();
    test_pop<std::string>();

    std::cout << CYAN "pop: " << GREEN "OK" END << std::endl;
}

static void test_relational_operators_practical()
{
    lib_used::stack<int> foo;
    lib_used::stack<int> bar;

    foo.push(0);
    bar.push(1);

    assert(foo < bar);
    assert(foo <= bar);
    assert(bar > foo);
    assert(bar >= foo);
    assert(bar != foo);
    assert(foo != bar);
}

template <typename T>
static void test_relational_operators()
{
    lib_used::stack<T> foo;
    lib_used::stack<T> bar;

    foo.push(T());

    assert(foo > bar);
    assert(foo >= bar);
    assert(!(foo < bar));
    assert(!(foo <= bar));
    assert(bar < foo);
    assert(bar <= foo);
    assert(bar != foo);
    assert(foo != bar);
    assert(bar == bar);
    assert(foo == foo);
}

static void relational_operators()
{
    test_relational_operators_practical();
    test_relational_operators<int>();

    std::cout << CYAN "relational operators: " << GREEN "OK" END << std::endl;
}

int main()
{
    std::cout << YELLOW "========= TEST lib_used::STACK =========" END << std::endl;

    std::cout << WHITE "=== Member functions" END << std::endl;
    default_constuctor();
    empty();
    size();
    top();
    push();
    pop();

    std::cout << WHITE "=== Non-member function overloads" END << std::endl;
    relational_operators();

    std::cout << std::endl;
    return (0);
}
// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "SlowSlerp.h"
#include "FastSlerp.h"
#include <DirectXMath.h>
#include <time.h>

#define TESTCOUNT 100000;



int main()
{
	Quaternion test1;
	XQuaternion test2;
	int length = TESTCOUNT;
    std::cout << "Hello World!\n"; 

	std::cout << "Hello World!\n";
	Quaternion v1 = { 500, 500, 500 ,500 };
	Quaternion v2 = { 300, 300, 300 ,300 };
	XQuaternion v3 = { 500, 500, 500 ,500 };
	XQuaternion v4 = { 300, 300, 300 ,300 };
	DirectX::XMVECTOR v5 = DirectX::XMVectorSet(500, 500, 500, 500);
	DirectX::XMVECTOR v6 = DirectX::XMVectorSet(300, 300, 300, 300);
	SlowSlerp slow;
	FastSlerp fast;
	clock_t start3, end3;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < length; i++) { DirectX::XMVECTOR  test0 = DirectX::XMQuaternionSlerp(v5, v6, 5); }
	auto finish = std::chrono::high_resolution_clock::now();
	start3 = clock();
	for (int i = 0; i < length; i++) { test1 = slow.SlerpSlow(v1, v2, 5); }
	
	
	end3 = clock();

	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "Elapsed time: " << elapsed.count() << " s\n";
	std::cout << "Time: " << (double)(end3 - start3) / CLOCKS_PER_SEC << "s\n";

	auto start1 = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < length; i++) {  test2 = fast.SlerpFast(v3, v4, 5); }
	auto finish1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed1 = finish1 - start1;
	std::cout << "Elapsed time: " << elapsed1.count() << " s\n";


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file



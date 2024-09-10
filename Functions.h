#pragma once
#include <iostream>
#include <fstream>

using namespace std;

// Function to open, read, and create 1d array
void readArrayFromFile(int*& arr, int& size, const string& filename);

// Function to check if a certain integer exists in the array
int findIndex(int arr[], int size, int value);

// Function to modify the value of an integer in the array
void modifyValue(int arr[], int size, int index, int newValue);

// Function to add a new integer to the end of the array
void addValue(int*& arr, int& size, int newValue);

// Function to replace a value in the array with 0 
void removeValue(int*& arr, int& size, int index);

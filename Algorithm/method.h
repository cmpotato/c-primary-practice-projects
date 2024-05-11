#pragma once

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string>

#define WORDMAXLENGTH 24

typedef struct LNode2009 {
	int data;
	struct LNode2009* link;
}LNode2009, * ListNode2009;

typedef struct LNode2012 {
	char data;
	struct LNode2012* link;
}LNode2012, * ListNode2012;

typedef struct LNode2015 {
	int data;
	struct LNode2015* link;
}LNode2015, * ListNode2015;

typedef struct LNode2019 {
	int data;
	struct LNode2019* next;
}LNode2019, * ListNode2019;

typedef struct TNode2014 {
	struct TNode2014* left;
	int weight;
	struct TNode2014* right;
}TNode2014, * TreeNode2014;


void quickSort(int arr[], int front, int rear);
int partition(int arr[], int front, int rear);


int method2010();
int method2011();
int method2013();
int method2018(int arr[], int n);
int method2020(int arr1[], int a1, int arr2[], int a2, int arr3[], int a3);
ListNode2009 setlist2009(int length);
int method2009(ListNode2009 list, int k);
int method2012();
ListNode2015 setlist2015();
int method2015(ListNode2015 head, int n);
TreeNode2014 GenerateTree2014();
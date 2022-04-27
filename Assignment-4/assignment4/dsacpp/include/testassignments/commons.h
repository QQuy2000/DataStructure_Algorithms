/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DLinkedListTest.h
 * Author: LTSACH
 *
 * Created on 25 August 2020, 11:15
 */

#ifndef COMMONS_H
#define COMMONS_H
#include "doctest.h"
#include "list/XArrayList.h"
#include "list/SLinkedList.h"
#include "list/DLinkedList.h"
#include "stacknqueue/IDeck.h"
#include "stacknqueue/Stack.h"
#include "stacknqueue/Queue.h"
#include "util/ArrayLib.h"
#include "geom/Point3D.h"
#include "geom/Vector3D.h"


#include "tree/AVL.h"
#include "util/FileIOLib.h"
#include "util/ArrayLib.h"
#include <sstream>
#include <bits/stdc++.h>
 #include <cmath>

using namespace std;

/*
 REF: https://www.thecrazyprogrammer.com/2021/01/c-string-trim.html
 */
string trimstring(string str) {
    const char* typeOfWhitespaces = " \t\n\r\f\v";
    str.erase(str.find_last_not_of(typeOfWhitespaces) + 1);
    str.erase(0,str.find_first_not_of(typeOfWhitespaces));
    return str;
}

using namespace std;

int nsizes = 20;
int max_length = 100;

#endif /* COMMONS_H */


//
// Created by Hrayr on 5/31/2020.
//

#ifndef DATABASE_ARRAYHELPER_H
#define DATABASE_ARRAYHELPER_H

class String;

class ArrayHelper {
public:

    bool resize(String *f, long long int size = 1);

    static bool resize(struct column *columns, long long size = 1);

    static bool resize(long long *&f, long long size = 1);

    static bool resize(void **&f, long long size = 1);

    static long long int count(long long int *array);

    static long long int count(String *array);
};


#endif //DATABASE_ARRAYHELPER_H

/**************************************************************************
//
// Copyright:THDMI
//
// Author: HDM
//
// Date:2020-05-24
//
// Description:Calculate the Graphic according with Matrix and Length
//
**************************************************************************/

#pragma once

/*
* @description 计算自定义距离长度下矩阵的自定义点通路或回路个数，当且仅当pointRow == pointLine
* @param **matrixArray 初始矩阵指针
* @param matrixSize 矩阵尺度
* @param *customLengthArray 自定义长度数组
* @param getLenArraySize 自定义长度尺度
* @param pointRow 自定义点横坐标
* @param pointLine 自定义点的纵坐标
* @param *acceptLengthArray 自定义长度的自定义点通路或回路个数、调用方接收结果数组的指针
*/
void getArrayCustomMultiLength(int** matrixArray, int matrixSize, int* customLengthArray, int customLengthSize, int pointRow, int pointLine, int* acceptLengthArray);



/*
* @description 统计某范围长度内自定义点的通路或回路之和，当且仅当pointRow == pointLine
* @param **matrixArray 初始矩阵指针
* @param matrixSize 矩阵尺度
* @param maxLength 最大距离长度
* @param pointRow 自定义点的横坐标
* @param pointLine 自定义点的纵坐标
* @return sumRangeLengthArray 某范围长度内自定义点的通路或回路之和
*/
int getCountPointRangeLength(int** matrixArray, int matrixSize, int maxLength, int pointRow, int pointLine);



/*
* @description 求某长度内所有点即通路和回路之和
* @param **matrixArray 调用方矩阵指针
* @param matrixSize 矩阵尺度
* @param maxLength 最大距离长度
* @return sumRangeLengthArray 某长度内所有点即通路和回路之和
*/
int getAllPointRangeLengthAccess_HaveLoop(int** matrixArray, int matrixSize, int maxLength);



/*
* @description 求某长度内所有通路之和（不包括回路）
* @param **matrixArray 调用方矩阵指针
* @param matrixSize 矩阵尺度
* @param maxLength 最大距离长度
* @return sumRangeLengthArray 某长度内所有通路之和（不包括回路）
*/
int getAllPointRangeLengthAccess_NotLoop(int** matrixArray, int matrixSize, int maxLength);



/*
* @description 求某长度内所有回路之和
* @param **matrixArray 调用方矩阵指针
* @param matrixSize 矩阵尺度
* @param maxLength 最大距离长度
* @return sumRangeLengthArray 某长度内所有回路之和
*/
int getAllPointRangeLengthLoop(int** matrixArray, int matrixSize, int maxLength);



/*
* @description 初始化矩阵
* @param matrixArray 初始矩阵，调用方指针、接收结果矩阵的调用方指针
* @param matrixSize 矩阵尺度
*/
void setMatrixArray(int** matrixArray, int matrixSize);



/*
* @description 矩阵乘积计算
* @param **matrixArray 调用方矩阵
* @param **aheadMatrixArray 前矩阵
* @param **afterMatrixArray 后矩阵
* @param matrixSize 矩阵尺度
* @param **acceptCalculateMatrix 接收矩阵的调用方指针
*/
void multiplicineMatrixCalculate(int** aheadMatrixArray, int** afterMatrixArray, int matrixSize, int** acceptCalculateMatrix);



/*
* @description 计算某个距离长度的矩阵
* @param **matrixArray 初始矩阵、接收矩阵的调用方指针
* @param matrixSize 矩阵尺度
* @param setLength 距离长度
*/
void multiplicineMatrixResult(int** matrixArray, int matrixSize, int setLength);



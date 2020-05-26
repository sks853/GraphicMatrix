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
* @description 
* @param **matrixArray 
* @param matrixSize 
* @param *customLengthArray 
* @param getLenArraySize 
* @param pointRow 
* @param pointLine 
* @param *acceptLengthArray 
*/
void getArrayCustomMultiLengthAccess(int** matrixArray, int matrixSize, int* customLengthArray, int customLengthSize, int pointRow, int pointLine, int* acceptLengthArray);

/*
* @description 
* @param **matrixArray 
* @param matrixSize 
* @param *customLengthArray 
* @param getLenArraySize 
* @param pointLoop 
* @param *acceptLengthArray 
*/
void getArrayCustomMultiLengthLoop(int** matrixArray, int matrixSize, int* customLengthArray, int customLengthSize, int pointLoop, int* acceptLengthArray);

/*
* @description 
* @param **matrixArray 
* @param matrixSize 
* @param maxLength 
* @param pointRow 
* @param pointLine 
* @return sumRangeLengthArray 
*/
int getCountPointRangeLengthAccess(int** matrixArray, int matrixSize, int maxLength, int pointRow, int pointLine);

/*
* @description 
* @param **matrixArray 
* @param matrixSize 
* @param maxLength 
* @param pointLoop 
* @return sumRangeLengthArray 
*/
int getCountPointRangeLengthLoop(int** matrixArray, int matrixSize, int maxLength, int pointLoop);

/*
* @description 
* @param **matrixArray 
* @param matrixSize 
* @param maxLength 
* @param pointRowAny 
* @param pointLineAny 
* @return sumRangeLengthArray 
*/
int getAllPointRangeLengthAccess(int** matrixArray, int matrixSize, int maxLength, int pointRowAny, int pointLineAny);

/*
* @description 
* @param **matrixArray 
* @param matrixSize 
* @param maxLength 
* @param pointRowAny 
* @param pointLineAny 
* @return sumRangeLengthArray 
*/
int getAllPointRangeLengthAccessNotLoop(int** matrixArray, int matrixSize, int maxLength, int pointRowAny, int pointLineAny);

/*
* @description 
* @param **matrixArray 
* @param matrixSize 
* @param maxLength 
* @param pointLoopAny 
* @return sumRangeLengthArray 
*/
int getAllPointRangeLengthLoop(int** matrixArray, int matrixSize, int maxLength, int pointLoopAny);

/*
* @description 
* @param matrixSize 
*/
void setMatrixArray(int** matrixArray, int matrixSize);

/*
* @description 
* @param **matrixArray 
* @param **aheadMatrixArray 
* @param **afterMatrixArray 
* @param matrixSize 
* @param **acceptCalculateMatrix 
*/
void multiplicineMatrixCalculate(int** aheadMatrixArray, int** afterMatrixArray, int matrixSize, int** acceptCalculateMatrix);

/*
* @description 
* @param **matrixArray 
* @param matrixSize 
* @param setLength 
*/
void multiplicineMatrixResult(int** matrixArray, int matrixSize, int setLength);



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

#include "StartMain.h"
#include <malloc.h>
#include <iostream>

struct PointArrayAddressMatrix
{
	int** matrixArray;
	int** address;

};

struct ArrayAndArray
{
	int* inputlengthArray;
	int* resultCountRoadArray;
};

int** inputMatrix(int order);
int** matrixResultMUL(int** temporMatrixArray, int order, int length);
int** matrixCalculateMUL(int** aheadMatrix, int** afterMatrix, int order);
int countRangeLengthAccess(int** matrixArray, int order, int length, int accessRow, int accessLine);
int countRangeLengthLoop(int** matrixArray, int order, int length, int loopRowLine);
int* getMultiLengthAccess(int** matrixArray, int order, int* getLengthArray, int getLenArraySize, int accessRow, int accessLine);
int* getMultiLengthLoop(int** matrixArray, int order, int* length, int loopRowLine);


/*
* @description 初始化录入矩阵
* @param order 阶数
* @return **funMatrixArray 二维数组指针
*/
int** inputMatrix(int order)
{
	// 动态分配二维数组
	int** initialMatrixArray = (int**)malloc(order * sizeof(int*));

	for (int i = 0; i < order; i++)
	{
		initialMatrixArray[i] = (int*)malloc(order * sizeof(int));
	}

	// 存放数组内容
	std::cout << "Please input matrix: (Space off) " << std::endl;
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			std::cin >> initialMatrixArray[i][j];
		}
	}
	return initialMatrixArray;
}

/*
* @description 根据长度判断矩阵需要累乘多少次并返回累乘结果
* @param **temporMatrixArray 指针数组
* @param order 阶数
* @param length 两点长度，默认0次
* @return **calculatedMatrix 累乘后最终结果
*/
int** matrixResultMUL(int** temporMatrixArray, int order, int length)
{
	// 初始化动态分配数组
	int** originalMatrix = (int**)malloc(order * sizeof(int*));
	int** calculatedMatrix = (int**)malloc(order * sizeof(int*));

	for (int i = 0; i < order; i++)
	{
		originalMatrix[i] = (int*)malloc(order * sizeof(int));
		calculatedMatrix[i] = (int*)malloc(order * sizeof(int));
	}

	// 赋予调用方传入的参数值
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			originalMatrix[i][j] = temporMatrixArray[i][j];
			calculatedMatrix[i][j] = temporMatrixArray[i][j];
		}
	}

	// 根据长度不断回调计算最终阶乘矩阵
	for (int i = 0; i < length - 1; i++)
	{
		calculatedMatrix = matrixCalculateMUL(originalMatrix, calculatedMatrix, order);
	}

	free(originalMatrix);
	originalMatrix = 0;
	return calculatedMatrix;
}

/*
* @description 矩阵累乘计算
* @param **temporMatrixArray 指针数组
* @param order 阶数
* @return **calculateMatrix 累乘临时结果
*/
int** matrixCalculateMUL(int** aheadMatrix, int** afterMatrix, int order)
{
	int orderSum = 0;
	int** calculateTemporMatrix = (int**)malloc(order * sizeof(int*));
	for (int i = 0; i < order; i++)
	{
		calculateTemporMatrix[i] = (int*)malloc(order * sizeof(int));
	}

	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			orderSum = 0;
			for (int k = 0; k < order; k++)
			{
				orderSum = orderSum + aheadMatrix[i][k] * afterMatrix[k][j];
				calculateTemporMatrix[i][j] = orderSum;
			}
		}
	}
	return calculateTemporMatrix;
}

/*
* @description 求length长度内的通路个数之和
* @param **matrixArray 矩阵
* @param order 阶数
* @param length 距离长度
* @param accessRow 某点所在行
* @param accessLine 某点所在列
* @return countRangeAccessSum length范围内的某点到另点通路之和
*/
int countRangeLengthAccess(int** matrixArray, int order, int length, int accessRow, int accessLine)
{
	int countRangeAccessSum = 0;

	// 初始化动态分配数组
	int** originalMatrix = (int**)malloc(order * sizeof(int*));
	int** calculatedMatrix = (int**)malloc(order * sizeof(int*));

	for (int i = 0; i < order; i++)
	{
		originalMatrix[i] = (int*)malloc(order * sizeof(int));
		calculatedMatrix[i] = (int*)malloc(order * sizeof(int));
	}

	// 赋予调用方传入的参数值
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			originalMatrix[i][j] = matrixArray[i][j];
			calculatedMatrix[i][j] = matrixArray[i][j];
		}
	}

	// 根据通路长度不断回调计算最终阶乘矩阵
	for (int i = 0; i < length - 1; i++)
	{
		calculatedMatrix = matrixCalculateMUL(originalMatrix, calculatedMatrix, order);
		std::cout << "\n===================\n" << std::endl;
		// ------------------------------------------ Test Out ---------------------------------------------
		for (int m = 0; m < length; m++)
		{
			for (int n = 0; n < length; n++)
			{
				std::cout << calculatedMatrix[m][n] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << "\n===================\n" << std::endl;
		countRangeAccessSum = countRangeAccessSum + calculatedMatrix[accessRow - 1][accessLine - 1];
	}

	free(originalMatrix);
	originalMatrix = 0;
	free(calculatedMatrix);
	calculatedMatrix = 0;

	return countRangeAccessSum;
}

/*
* @description 求length长度内的回路个数之和
* @param **matrixArray 矩阵
* @param order 阶数
* @param length 距离长度
* @param loopRowLine 某点坐标
* @return countRangeAccessSum length范围内的某点自身回路之和
*/
int countRangeLengthLoop(int** matrixArray, int order, int length, int loopRowLine)
{
	int countRangeLoopSum = 0;

	// 初始化动态分配数组
	int** originalMatrix = (int**)malloc(order * sizeof(int*));
	int** calculatedMatrix = (int**)malloc(order * sizeof(int*));

	for (int i = 0; i < order; i++)
	{
		originalMatrix[i] = (int*)malloc(order * sizeof(int));
		calculatedMatrix[i] = (int*)malloc(order * sizeof(int));
	}

	// 赋予调用方传入的参数值
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			originalMatrix[i][j] = matrixArray[i][j];
			calculatedMatrix[i][j] = matrixArray[i][j];
		}
	}

	// 根据回路长度不断回调计算最终阶乘矩阵
	for (int i = 0; i < length - 1; i++)
	{
		calculatedMatrix = matrixCalculateMUL(originalMatrix, calculatedMatrix, order);
		countRangeLoopSum = countRangeLoopSum + calculatedMatrix[loopRowLine - 1][loopRowLine - 1];
	}

	free(originalMatrix);
	originalMatrix = 0;
	free(calculatedMatrix);
	calculatedMatrix = 0;

	return countRangeLoopSum;
}

/*
* @description 求多个距离长度的矩阵的某个点的通路
* @param **matrixArray 矩阵
* @param order 阶数
* @param *getLengthArray 所求距离的数组
* @param getLenArraySize 所求距离的数组的大小
* @param accessRow 某点坐标的横坐标
* @param accessLine 某点坐标的纵坐标
* @return *countSinglePointAccessArray 包含所求距离的通路个数的数组
*/
int* getMultiLengthAccess(int** matrixArray, int order, int* getLengthArray, int getLenArraySize, int accessRow, int accessLine)
{
	// 初始化动态分配数组
	int** originalMatrix = (int**)malloc(order * sizeof(int*));
	int** calculatedMatrix = (int**)malloc(order * sizeof(int*));

	for (int i = 0; i < order; i++)
	{
		originalMatrix[i] = (int*)malloc(order * sizeof(int));
		calculatedMatrix[i] = (int*)malloc(order * sizeof(int));
	}

	// 赋予调用方传入的参数值
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			originalMatrix[i][j] = matrixArray[i][j];
			calculatedMatrix[i][j] = matrixArray[i][j];
		}
	}

	// 所求每个长度的通路个数集合
	int* countSinglePointAccessArray = (int*)malloc(order * sizeof(int));
	for (int i = 0; i < order; i++)
	{
		countSinglePointAccessArray[i] = 0;
	}

	// 将所有可能的长度都求出来，然后每个长度的点的值都取出来放到countSinglePointAccessArray[]
	for (int i = 0; i < order; i++)
	{
		calculatedMatrix = matrixCalculateMUL(originalMatrix, calculatedMatrix, order);
		countSinglePointAccessArray[i] = calculatedMatrix[accessRow][accessLine];
	}

	// 根据getLengthArray[i]里的值，取出countSinglePointAccessArray[getLengthArray[i]]的值并传递给getLengthArray
	for (int i = 0; i < getLenArraySize; i++)
	{
		getLengthArray[i] = countSinglePointAccessArray[getLengthArray[i] - 1];
	}

	free(originalMatrix);
	originalMatrix = 0;
	free(calculatedMatrix);
	calculatedMatrix = 0;

	return countSinglePointAccessArray;
}


int* getMultiLengthLoop(int** matrixArray, int order, int* length, int loopRowLine)
{
	std::cout << std::endl;
	return 0;
}


int mains(int argc, char** argv[], char** env[])
{
	/*
	* order 阶数
	* length 距离/长度
	* pointRow 代表通路个数的点所在矩阵的横坐标
	* pointLine 代表通路个数的点所在矩阵的纵坐标
	* pointLoop 代表通路个数的点所在矩阵的横坐标等于纵坐标
	*/
	int order = 1;
	int length = 0;
	int pointRow = 1;
	int pointLine = 1;
	int pointLoop = 1;

	// 输入矩阵阶数和长度以及通路、回路的点的坐标
	std::cout << "Please input order of matrix: ";
	std::cin >> order;
	std::cout << "Please input length or distance of matrix: ";
	std::cin >> length;
	std::cout << "Please input pointRow: ";
	std::cin >> pointRow;
	std::cout << "Please input pointLine: ";
	std::cin >> pointLine;
	std::cout << "Please input pointLoop: ";
	std::cin >> pointLoop;

	int lengthSize = 5;
	int* setLength = (int*)malloc(lengthSize * sizeof(int));

	for (int i = 0; i < lengthSize; i++)
	{
		std::cout << "Please input length: " << i << std::endl;
		std::cin >> setLength[i];
	}

	// 初始化输入矩阵
	int** matrixArray = inputMatrix(order);

	// 减少空指针异常
	if (order < 1 || length < 0 || pointRow < 1 || pointLine < 1 || pointLoop < 1)
	{
		std::cout << "\nError Input ! \n" << std::endl;
		return -1;
	}

	// --------------------------------------------------- Test Output -----------------------------------------------------
	int controls = 0;
	std::cout << "Please input control (1 or 2 or 3) : ";
	std::cin >> controls;

	switch (controls)
	{
	case 1:
		// 求length长度的矩阵
		matrixArray = matrixResultMUL(matrixArray, order, length);
		break;
	case 2:
		std::cout << "The sum of access of length in range point to point is : " << countRangeLengthAccess(matrixArray, order, length, pointRow, pointLine) << std::endl;
		std::cout << "The sum of loop of length in range point self is : " << countRangeLengthLoop(matrixArray, order, length, pointLoop) << std::endl;
		break;
	case 3:

		setLength = getMultiLengthAccess(matrixArray, order, setLength, lengthSize, pointRow, pointLine);
		for (int i = 0; i < lengthSize; i++)
		{
			std::cout << "用户自定义的通路所得到的结果为" << i << " : " << setLength[i] << std::endl;
		}

		free(setLength);
		break;
	case 4:

		break;
	default:
		break;
	}

	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			std::cout << matrixArray[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
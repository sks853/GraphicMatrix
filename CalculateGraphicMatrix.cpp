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

#include "CalculateGraphicMatrix.h"
#include <malloc.h>
#include <iostream>


/************************************* 已验证 ****************************************/
int getPointSetLength(int** matrixArray, int matrixSize, int setLength, int pointRow, int pointLine)
{
	int pointValue = 0;
	int** calculateTemporMatrixArray = (int**)malloc(matrixSize * sizeof(int*));
	for (int i = 0; i < matrixSize; i++)
	{
		calculateTemporMatrixArray[i] = (int*)malloc(matrixSize * sizeof(int));
	}
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			calculateTemporMatrixArray[i][j] = matrixArray[i][j];
		}
	}

	for (int i = 1; i < setLength; i++)
	{
		multiplicineMatrixCalculate(matrixArray, calculateTemporMatrixArray, matrixSize, calculateTemporMatrixArray);
	}
	pointValue = calculateTemporMatrixArray[pointRow - 1][pointLine - 1];

	for (int i = 0; i < matrixSize; i++)
	{
		free(calculateTemporMatrixArray[i]);
	}
	free(calculateTemporMatrixArray);
	return pointValue;
}


/************************************* 已验证 ****************************************/
void getArrayCustomMultiLength(int** matrixArray, int matrixSize, int* customLengthArray, int customLengthSize, int pointRow, int pointLine, int* acceptResultArray)
{
	int** calculateTemporMatrixArray = (int**)malloc(matrixSize * sizeof(int*));
	for (int i = 0; i < matrixSize; i++)
	{
		calculateTemporMatrixArray[i] = (int*)malloc(matrixSize * sizeof(int));
	}
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			calculateTemporMatrixArray[i][j] = matrixArray[i][j];
		}
	}

	// 获取自定义长度数组里面最长的长度 -- 获取到最大长度后只需要不断阶乘到该长度，获取想要的序号即可
	int maxCustomLength = 1;
	for (int i = 0; i < customLengthSize; i++)
	{
		if (maxCustomLength < customLengthArray[i])
		{
			maxCustomLength = customLengthArray[i];
		}
	}
	int* calculateTemporLengthArray = (int*)malloc(customLengthSize * sizeof(int));

	for (int i = 0; i < maxCustomLength; i++)
	{
		calculateTemporLengthArray[i] = calculateTemporMatrixArray[pointRow - 1][pointLine - 1];
		multiplicineMatrixCalculate(matrixArray, calculateTemporMatrixArray, matrixSize, calculateTemporMatrixArray);
	}

	// 遍历用户自定义长度数组 -- 并把calculateTemporLengthArray[customLengthArray[i]]传给acceptResultArray[i]
	for (int i = 0; i < customLengthSize; i++)
	{
		acceptResultArray[i] = calculateTemporLengthArray[customLengthArray[i] - 1];
	}

	for (int i = 0; i < matrixSize; i++)
	{
		free(calculateTemporMatrixArray[i]);
	}
	free(calculateTemporMatrixArray);
	free(calculateTemporLengthArray);
}


/************************************* 已验证 ****************************************/
int getCountPointRangeLength(int** matrixArray, int matrixSize, int maxLength, int pointRow, int pointLine)
{
	int sumRangeLengthArray = 0;
	int** calculateTemporMatrixArray = (int**)malloc(matrixSize * sizeof(int*));
	for (int i = 0; i < matrixSize; i++)
	{
		calculateTemporMatrixArray[i] = (int*)malloc(matrixSize * sizeof(int));
	}
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			calculateTemporMatrixArray[i][j] = matrixArray[i][j];
		}
	}

	for (int i = 1; i < maxLength; i++)
	{
		multiplicineMatrixCalculate(matrixArray, calculateTemporMatrixArray, matrixSize, calculateTemporMatrixArray);
		sumRangeLengthArray = sumRangeLengthArray + calculateTemporMatrixArray[pointRow - 1][pointLine - 1];
	}

	for (int i = 0; i < matrixSize; i++)
	{
		free(calculateTemporMatrixArray[i]);
	}
	free(calculateTemporMatrixArray);

	return sumRangeLengthArray;
}


/************************************* 待设计 ****************************************/
int getAllPointRangeLengthAccess_HaveLoop(int** matrixArray, int matrixSize, int maxLength)
{
	int sumRangeLengthArray = 0;
	int pointRowAny = 1;
	int pointLineAny = 1;

	// TODO: 在此处添加实现代码.
	return sumRangeLengthArray;
}


/************************************* 待设计 ****************************************/
int getAllPointRangeLengthAccess_NotLoop(int** matrixArray, int matrixSize, int maxLength)
{
	int sumRangeLengthArray = 0;
	int pointRowAny = 1;
	int pointLineAny = 1;

	// TODO: 在此处添加实现代码.
	return sumRangeLengthArray;
}


/************************************* 待设计 ****************************************/
int getAllPointRangeLengthLoop(int** matrixArray, int matrixSize, int maxLength)
{
	int sumRangeLengthArray = 0;
	int pointLoopAny = 1;

	// TODO: 在此处添加实现代码.
	return sumRangeLengthArray;
}


/************************************* 已验证 ****************************************/
void setMatrixArray(int** matrixArray, int matrixSize)
{
	std::cout << "Please input matrix: (Space off) " << std::endl;
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			scanf_s("%d", &matrixArray[i][j]);
		}
	}
}


/************************************* 已验证 ****************************************/
void multiplicineMatrixCalculate(int** aheadMatrixArray, int** afterMatrixArray, int matrixSize, int** acceptCalculateMatrix)
{
	// 前行×后列之和
	int mulOrderSum = 0;
	int** calculateTemporMatrix = (int**)malloc(matrixSize * sizeof(int*));
	for (int i = 0; i < matrixSize; i++)
	{
		calculateTemporMatrix[i] = (int*)malloc(matrixSize * sizeof(int));
	}

	// 矩阵阶乘
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			mulOrderSum = 0;
			for (int k = 0; k < matrixSize; k++)
			{
				mulOrderSum = mulOrderSum + aheadMatrixArray[i][k] * afterMatrixArray[k][j];
				calculateTemporMatrix[i][j] = mulOrderSum;
			}
		}
	}

	// 传递计算结果值给调用方指针
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			acceptCalculateMatrix[i][j] = calculateTemporMatrix[i][j];
		}
	}

	// Free
	for (int i = 0; i < matrixSize; i++)
	{
		free(calculateTemporMatrix[i]);
	}

	free(calculateTemporMatrix);
}


/************************************* 已验证 ****************************************/
void multiplicineMatrixResult(int** matrixArray, int matrixSize, int setLength)
{
	int** calculatedMatrix = (int**)malloc(matrixSize * sizeof(int*));
	for (int i = 0; i < matrixSize; i++)
	{
		calculatedMatrix[i] = (int*)malloc(matrixSize * sizeof(int));
	}
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			calculatedMatrix[i][j] = matrixArray[i][j];
		}
	}

	for (int i = 0; i < setLength - 1; i++)
	{
		multiplicineMatrixCalculate(matrixArray, calculatedMatrix, matrixSize, calculatedMatrix);
	}

	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			matrixArray[i][j] = calculatedMatrix[i][j];
		}
	}

	for (int i = 0; i < matrixSize; i++)
	{
		free(calculatedMatrix[i]);
	}
	free(calculatedMatrix);
}

/********
0 0 0 0 1
1 0 1 1 0
0 0 1 0 0
0 0 1 0 1
0 1 0 1 0
********/

/*
				a     b     c     d     e

		  a   (1,1) (1,2) (1,3) (1,4) (1,5)
		  b   (2,1) (2,2) (2,3) (2,4) (2,5)
		  c   (3,1) (3,2) (3,3) (3,4) (3,5)
		  d   (4,1) (4,2) (4,3) (4,4) (4,5)
		  e   (5,1) (5,2) (5,3) (5,4) (5,5)
*/
int main(int argc, char** argv[], char** env[])
{
	// -------------------------- 设置矩阵阶数 -------------------------- //
	int matrixSize = 0;
	std::cout << "设置矩阵的阶数：";
	scanf_s("%d", &matrixSize);

	// -------------------------- 初始化矩阵数组(动态分配二维数组) -------------------------- //
	int** matrixArray = (int**)malloc(matrixSize * sizeof(int*));
	for (int i = 0; i < matrixSize; i++)
	{
		matrixArray[i] = (int*)malloc(matrixSize * sizeof(int));
	}
	setMatrixArray(matrixArray, matrixSize);

	// ---------------------------------------- Test:求长度为3的矩阵 ---------------------------------------- //
	//multiplicineMatrixResult(matrixArray, matrixSize, 2);

	// ---------------------------------------- Test:求长度范围为0-3，点(1,4)的通路之和 ---------------------------------------- //
	//std::cout << getCountPointRangeLength(matrixArray, matrixSize, 3, 1, 4) << std::endl;

	// ---------------------------------------- Test:求长度为3的通路（即某点的值） ---------------------------------------- //
	//std::cout << getPointSetLength(matrixArray, matrixSize, 3, 1, 4) << std::endl;

	// ---------------------------------------- Test:求自定义的多个长度的通路或回路 ---------------------------------------- //
	//int testLengthSize = 4;
	//int testLength[4] = { 1,2,3,4 };
	//int* acceptArray = (int*)malloc(testLengthSize * sizeof(int));	
	//getArrayCustomMultiLength(matrixArray, matrixSize, testLength, testLengthSize, 1, 3, acceptArray);
	//for (int i = 0; i < testLengthSize; i++)
	//{
	//	std::cout << i << ":" << acceptArray[i] << std::endl;;
	//}
	//free(acceptArray);

	// ------------------------------------------------------------------------------------------------------ //
	// -------------------------------------------- TEST OUT ------------------------------------------------ //
	// ------------------------------------------------------------------------------------------------------ //
	// 
	std::cout << "\n======================= Test Out =======================\n" << std::endl;
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			std::cout << matrixArray[i][j] << " ";
		}
		std::cout << std::endl;
	}
	// 
	// ------------------------------------------------------------------------------------------------------ //
	// -------------------------------------------- TEST OUT ------------------------------------------------ //
	// ------------------------------------------------------------------------------------------------------ //

	for (int i = 0; i < matrixSize; i++)
	{
		free(matrixArray[i]);
	}
	free(matrixArray);

	return 0;
}
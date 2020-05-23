#include "StartMain.h"
#include <malloc.h>
#include <iostream>

struct PointArrayAddress
{
	int** matrixArray;
	int** address;

};

struct ArrayAndArray
{
	int* inputlengthArray;
	int* resultCountRoadArray;
};

int** inputMatrixArray(int order);
int** mulResultMatrix(int** temporMatrixArray, int order, int length);
int** mulCalculateMatrix(int** aheadMatrix, int** afterMatrix, int order);
int countRangePointToPointAccessMatrix(int** matrixArray, int order, int length, int accessRow, int accessLine);
int countRangePointToPointLoopMatrix(int** matrixArray, int order, int length, int loopRowLine);
int* countSinglePointAccessMatrix(int** matrixArray, int order, int* getLengthArray, int getLenArraySize, int accessRow, int accessLine);
int* countSinglePointLoopMatrix(int** matrixArray, int order, int* length, int loopRowLine);
int getCountPointAccess(int** matrix);
int getCountPointLoop(int** matrix);

/*
* @description ��ʼ��¼�����
* @param order ����
* @return **funMatrixArray ��ά����ָ��
*/
int** inputMatrixArray(int order)
{
	// ��̬�����ά����
	int** initialMatrixArray = (int**)malloc(order * sizeof(int*));

	for (int i = 0; i < order; i++)
	{
		initialMatrixArray[i] = (int*)malloc(order * sizeof(int));
	}

	// �����������
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
* @description ���ݳ����жϾ�����Ҫ�۳˶��ٴβ������۳˽��
* @param **temporMatrixArray ָ������
* @param order ����
* @param length ���㳤�ȣ�Ĭ��0��
* @return **calculatedMatrix �۳˺����ս��
*/
int** mulResultMatrix(int** temporMatrixArray, int order, int length)
{
	// ��ʼ����̬��������
	int** originalMatrix = (int**)malloc(order * sizeof(int*));
	int** calculatedMatrix = (int**)malloc(order * sizeof(int*));

	for (int i = 0; i < order; i++)
	{
		originalMatrix[i] = (int*)malloc(order * sizeof(int));
		calculatedMatrix[i] = (int*)malloc(order * sizeof(int));
	}

	// ������÷�����Ĳ���ֵ
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			originalMatrix[i][j] = temporMatrixArray[i][j];
			calculatedMatrix[i][j] = temporMatrixArray[i][j];
		}
	}

	// ���ݳ��Ȳ��ϻص��������ս׳˾���
	for (int i = 0; i < length - 1; i++)
	{
		calculatedMatrix = mulCalculateMatrix(originalMatrix, calculatedMatrix, order);
	}

	free(originalMatrix);
	originalMatrix = 0;
	return calculatedMatrix;
}

/*
* @description �����۳˼���
* @param **temporMatrixArray ָ������
* @param order ����
* @return **calculateMatrix �۳���ʱ���
*/
int** mulCalculateMatrix(int** aheadMatrix, int** afterMatrix, int order)
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
* @description ��length�����ڵ�ͨ·����֮��
* @param **matrixArray ����
* @param order ����
* @param length ���볤��
* @param accessRow ĳ��������
* @param accessLine ĳ��������
* @return countRangeAccessSum length��Χ�ڵ�ĳ�㵽���ͨ·֮��
*/
int countRangePointToPointAccessMatrix(int** matrixArray, int order, int length, int accessRow, int accessLine)
{
	int countRangeAccessSum = 0;

	// ��ʼ����̬��������
	int** originalMatrix = (int**)malloc(order * sizeof(int*));
	int** calculatedMatrix = (int**)malloc(order * sizeof(int*));

	for (int i = 0; i < order; i++)
	{
		originalMatrix[i] = (int*)malloc(order * sizeof(int));
		calculatedMatrix[i] = (int*)malloc(order * sizeof(int));
	}

	// ������÷�����Ĳ���ֵ
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			originalMatrix[i][j] = matrixArray[i][j];
			calculatedMatrix[i][j] = matrixArray[i][j];
		}
	}

	// ����ͨ·���Ȳ��ϻص��������ս׳˾���
	for (int i = 0; i < length - 1; i++)
	{
		calculatedMatrix = mulCalculateMatrix(originalMatrix, calculatedMatrix, order);
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
* @description ��length�����ڵĻ�·����֮��
* @param **matrixArray ����
* @param order ����
* @param length ���볤��
* @param loopRowLine ĳ������
* @return countRangeAccessSum length��Χ�ڵ�ĳ�������·֮��
*/
int countRangePointToPointLoopMatrix(int** matrixArray, int order, int length, int loopRowLine)
{
	int countRangeLoopSum = 0;

	// ��ʼ����̬��������
	int** originalMatrix = (int**)malloc(order * sizeof(int*));
	int** calculatedMatrix = (int**)malloc(order * sizeof(int*));

	for (int i = 0; i < order; i++)
	{
		originalMatrix[i] = (int*)malloc(order * sizeof(int));
		calculatedMatrix[i] = (int*)malloc(order * sizeof(int));
	}

	// ������÷�����Ĳ���ֵ
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			originalMatrix[i][j] = matrixArray[i][j];
			calculatedMatrix[i][j] = matrixArray[i][j];
		}
	}

	// ���ݻ�·���Ȳ��ϻص��������ս׳˾���
	for (int i = 0; i < length - 1; i++)
	{
		calculatedMatrix = mulCalculateMatrix(originalMatrix, calculatedMatrix, order);
		countRangeLoopSum = countRangeLoopSum + calculatedMatrix[loopRowLine - 1][loopRowLine - 1];
	}

	free(originalMatrix);
	originalMatrix = 0;
	free(calculatedMatrix);
	calculatedMatrix = 0;

	return countRangeLoopSum;
}

/*
* @description �������볤�ȵľ����ĳ�����ͨ·
* @param **matrixArray ����
* @param order ����
* @param *getLengthArray ������������
* @param getLenArraySize ������������Ĵ�С
* @param accessRow ĳ������ĺ�����
* @param accessLine ĳ�������������
* @return *countSinglePointAccessArray ������������ͨ·����������
*/
int* countSinglePointAccessMatrix(int** matrixArray, int order, int* getLengthArray, int getLenArraySize, int accessRow, int accessLine)
{
	// ��ʼ����̬��������
	int** originalMatrix = (int**)malloc(order * sizeof(int*));
	int** calculatedMatrix = (int**)malloc(order * sizeof(int*));

	for (int i = 0; i < order; i++)
	{
		originalMatrix[i] = (int*)malloc(order * sizeof(int));
		calculatedMatrix[i] = (int*)malloc(order * sizeof(int));
	}

	// ������÷�����Ĳ���ֵ
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			originalMatrix[i][j] = matrixArray[i][j];
			calculatedMatrix[i][j] = matrixArray[i][j];
		}
	}

	// ����ÿ�����ȵ�ͨ·��������
	int* countSinglePointAccessArray = (int*)malloc(order * sizeof(int));
	for (int i = 0; i < order; i++)
	{
		countSinglePointAccessArray[i] = 0;
	}

	// �����п��ܵĳ��ȶ��������Ȼ��ÿ�����ȵĵ��ֵ��ȡ�����ŵ�countSinglePointAccessArray[]
	for (int i = 0; i < order; i++)
	{
		calculatedMatrix = mulCalculateMatrix(originalMatrix, calculatedMatrix, order);
		countSinglePointAccessArray[i] = calculatedMatrix[accessRow][accessLine];
	}

	// ����getLengthArray[i]���ֵ��ȡ��countSinglePointAccessArray[getLengthArray[i]]��ֵ�����ݸ�getLengthArray
	for (int i = 0; i < getLenArraySize; i++)
	{
		getLengthArray[i] = countSinglePointAccessArray[getLengthArray[i] - 1];
	}

	// ����ͨ·���Ȳ��ϻص��������ս׳˾���
	/*for (int i = 0; i < order; i++)
	{
		calculatedMatrix = mulCalculateMatrix(originalMatrix, calculatedMatrix, order);
		for (int j = 0; j < getLenArraySize; j++)
		{
			if (i == getLengthArray[j])
			{
				countSinglePointAccessArray[i] = calculatedMatrix[accessRow - 1][accessLine - 1];
			}
		}

	}*/

	free(originalMatrix);
	originalMatrix = 0;
	free(calculatedMatrix);
	calculatedMatrix = 0;

	return countSinglePointAccessArray;
}


int* countSinglePointLoopMatrix(int** matrixArray, int order, int* length, int loopRowLine)
{
	std::cout << std::endl;
	return 0;
}

/*
* @description �����ĳ�����ͨ·����
* @param **matrix ����ָ������
* @return matrix ĳ�����ͨ·����
*/
int getCountPointAccess(int** matrix)
{
	int accessRow = 0;
	int accessLine = 0;
	std::cout << "Please input row of matrix: ";
	std::cin >> accessRow;
	std::cout << "Please input line of matrix: ";
	std::cin >> accessLine;
	std::cout << "The" << accessRow << " to " << accessLine << " is : " << matrix[accessRow - 1][accessLine - 1] << std::endl;
	return matrix[accessRow - 1][accessLine - 1];
}

/*
* @description �����ĳ��Ļ�·����
* @param **matrix ����ָ������
* @return matrix ĳ��Ļ�·����
*/
int getCountPointLoop(int** matrix)
{
	int loop = 0;
	std::cout << "Please input length of matrix: ";
	std::cin >> loop;
	std::cout << "The road of loop have " << matrix[loop - 1][loop - 1] << std::endl;
	return matrix[loop - 1][loop - 1];
}

int main(int argc, char** argv[], char** env[])
{
	/*
	* order ����
	* length ����/����
	* pointRow ����ͨ·�����ĵ����ھ���ĺ�����
	* pointLine ����ͨ·�����ĵ����ھ����������
	* pointLoop ����ͨ·�����ĵ����ھ���ĺ��������������
	*/
	int order = 1;
	int length = 0;
	int pointRow = 1;
	int pointLine = 1;
	int pointLoop = 1;

	// �����������ͳ����Լ�ͨ·����·�ĵ������
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

	// ��ʼ���������
	int** matrixArray = inputMatrixArray(order);

	// ���ٿ�ָ���쳣
	if (order < 1 || length < 0 || pointRow < 1 || pointLine < 1 || pointLoop < 1)
	{
		std::cout << "\nError Input ! \n" << std::endl;
		return -1;
	}

	// --------------------------------------------------- Test Output -----------------------------------------------------
	int controls = 0;
	std::cout << "Please input control (1 or 2) : ";
	std::cin >> controls;

	switch (controls)
	{
	case 1:
		// ��length���ȵľ���
		matrixArray = mulResultMatrix(matrixArray, order, length);
		break;
	case 2:
		std::cout << "The sum of access of length in range point to point is : " << countRangePointToPointAccessMatrix(matrixArray, order, length, pointRow, pointLine) << std::endl;
		std::cout << "The sum of loop of length in range point self is : " << countRangePointToPointLoopMatrix(matrixArray, order, length, pointLoop) << std::endl;
		break;
	case 3:
		break;
	case 4:
		break;
	default:
		break;
	}

	return 0;
}
//#include <iostream>
//
//using namespace std;
//
//// 원본의 별명(레퍼런스) 를 받아서 수정 → 원본 바뀜
//void SwapRef(int& a, int& b)
//{
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
//int main()
//{
//	int arr[] = { 5, 3, 2, 4, 1 };
//
//	// Swap 하기전 원본 값 확인
//	cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << endl;
//
//	// 배열의 칸 갯수 구해서,
//	int size = sizeof(arr) / sizeof(arr[0]);
//
//	for (int pass = 0; pass < size - 1; pass++) {
//		// 배열 갯수 만큼 반복(버블 정렬)
//		for (int i = 0; i + 1 < size; i++)
//		{
//			// 큰 값을 뒤로 보내기 위해 조건 검사
//			if (arr[i] > arr[i + 1])
//			{
//				SwapRef(arr[i], arr[i + 1]);
//				cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << endl;
//			}
//		}
//	}
//
//
//	return 0;
//}
//
//
//

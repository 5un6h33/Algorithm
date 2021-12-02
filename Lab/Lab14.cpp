// #include<iostream>
// #include<vector>

// using namespace std;

// int main() {
// 	vector<int> list;
// 	// vector를 1~100 사이의 random한 크기로 만들고 채우는 코드 구현
//     int num = rand() % 101;
//     list.resize(num);
//     for(int i = 0; i < num; i++)
//         list.at(i) = i;

//     cout << num << endl;

// 	int cnt = -1;
// 	while (1) {
// 		cnt++;
// 		try 
//         { 
//             list.at(cnt);
//         }
// 		catch (exception& e) 
//         {
//             cout << "현재 list는 " << cnt << "의 크기를 가지고 있다";
//         }
// 	}
// 	return 0;
// }

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{
    string filename;
    int row = 10, col = 10;
    ifstream ifs;
	ofstream ofs;
	ofs.open("temp.txt");

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            ofs << rand() % 101 << " ";
        }
        ofs << "\n";
    }

	ofs.close();

    cout << "파일 이름 : ";
    cin >> filename;

    try
    {
        ifs.open(filename);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    

    cout << "출력할 행 크기 : ";
    cin >> row;
    cout << "출력할 열 크기 : ";
    cin >> col;

    try
    {
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                cout << " ";
            }
            cout << endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    ifs.close();

	return 0;
}

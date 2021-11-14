// #include <iostream>
// using namespace std;

// class Point {
// private:
// 	int x;
// 	int y;
// 	static int numCreatedObjects;
// public:
// 	Point() : x(0), y(0) 
//     {
// 		numCreatedObjects++;
// 	}

// 	// int _x 와 int _y를 입력으로 받는 생성자
//     Point(int _x, int _y): x(_x), y(_y)
//     {
//         numCreatedObjects++;
//     }

// 	~Point() 
//     {
// 		cout << "Destructed..." << endl;
// 	}

// 	void setXY(int x, int y) {
// 		//this-> 사용한 초기화
//         this->x = x;
//         this->y = y;
// 	}

// 	int getX() const { return this->x; }
// 	int getY() const { return this->y; }

// 	// *this + pt2 -> 
// 	Point operator+(const Point& pt2) {
// 		Point result(this->x + pt2.getX(), this->y + pt2.getY());
//         return result;
// 	}

// 	//operator overloading(연산자 오버로딩)
// 	Point& operator=(const Point& pt) {
// 		this->x = pt.getX();
//         this->y = pt.getY();
//         return *this;
// 	}

// 	static int getNumCreatedObject() { return numCreatedObjects; }
// 	friend void print(const Point& pt);
// 	friend ostream& operator<<(ostream& cout, Point& pt);
// 	friend class SpyPoint;
// };

// //static 맴버 변수 초기화 (numCreatedObjects)
// int Point::numCreatedObjects = 0;


// //객체 call by reference시: const로 함수 입력시 const method만 함수에서 사용가능
// // const: 객체 내부의 member data가 상수(변하지 않는다)
// void print(const Point& pt) {
// 	cout << pt.x << ", " << pt.y << endl;
// }

// //Point operator+(Point& pt1, Point& pt2){
// //  Point result(pt1.getX() + pt2.get(X), pt1.getY() + pt2.getY());
// //  return result;
// //}

// ostream& operator<<(ostream& cout, Point& pt) {
// 	return cout << pt.getX() << ", " << pt.getY();
// }

// class SpyPoint {
// public:
// 	//다음과 같이 출력 되도록 hack_all_info함수 구현

// 	//Hacked by SpyPoint
// 	//x: 40
// 	//y: 60
// 	//numCreatedObj.: 10

// 	void hack_all_info(const Point& pt)
//     {
//         cout << "Hacked by SpyPoint" << endl; 
//         cout << "x: " << pt.getX() << endl;
//         cout << "y: " << pt.getY() << endl;
//         cout << "numCreatedObj.: " << pt.numCreatedObjects << endl << endl;
//     }
// };

// int main() {
// 	Point pt1(1, 2);
// 	cout << "pt1 : ";
// 	print(pt1);
// 	cout << endl;

// 	// 포인터
// 	Point* pPt1 = &pt1;
// 	// pPt1의 값을 통해 getX, getY를 호출하여 출력
// 	cout << "pt1 : ";
// 	cout << (*pPt1).getX() << ", " << (*pPt1).getY() << endl;
// 	// pPt1를 통해 호출 getX, getY를 호출하여 출력
// 	cout << "pt1 : ";
//     cout << pPt1->getX() << ", " << pPt1->getY() << endl;

// 	cout << endl;

// 	//동적으로 Point* pPt2할당하여 10,20넣은 뒤 ->사용하여 출력(pt1 출력 참고)
// 	Point* pPt2 = new Point(10, 20);
// 	cout << "pt2 : ";
// 	cout << pPt2->getX() << ", " << pPt2->getY() << endl;
// 	cout << endl;
	
// 	//pPt2의 메모리 해제
//     delete pPt2;

// 	cout << "pt1 NumCreatedObject : ";
// 	cout << pt1.getNumCreatedObject() << endl;

// 	// 연산자 오버로딩
// 	//pt4 = pt2, pt3값 더하기
	
//     Point pt2(10, 20);
//     Point pt3(30, 40);
//     Point pt4;
//     pt4 = pt2 + pt3;

// 	cout << "pt2 : ";
// 	cout << pt2 << endl;
// 	cout << "pt3 : ";
// 	cout << pt3 << endl;
// 	cout << "pt4 : ";
// 	cout << pt4 << endl;

// 	cout << "pt1 NumCreatedObject : ";
// 	cout << pt1.getNumCreatedObject() << endl << endl;

// 	// object array
// 	Point* ptAry = new Point[5];
// 	cout << "pt2 NumCreatedObject : ";
// 	cout << pt2.getNumCreatedObject() << endl;
// 	cout << endl;

// 	// ptAry 메모리 해제
// 	delete[] ptAry;

// 	cout << endl;

// 	// friend class
// 	SpyPoint spy;
// 	cout << "pt1 info" << endl;
//     spy.hack_all_info(pt1);
// 	cout << "pt4 info" << endl;
// 	spy.hack_all_info(pt4);

// 	return 0;
// }

// #include<iostream>
// #include<cmath>

// using namespace std;

// class Point {
// private: 
//     double x, y;

// public: 
//     Point(): x(0), y(0){}
//     Point(int _x, int _y): x(_x), y(_y){}
//     ~Point() {}
//     int getX() const {return this->x;}
//     int getY() const {return this->y;}
//     void setPoint(int x, int y)
//     {
//         this->x = x;
//         this->y = y;
//     }
//     double square()
//     {
//         return sqrt(this->x + this->y);
//     }
//     Point operator-(const Point& pt)
//     {
//         Point result(this->x - pt.getX(), this->y - pt.getY());
//         return result;
//     }
//     Point operator*(const Point& pt)
//     {
//         Point result(this->x * pt.getX(), this->y * pt.getY());
//         return result;
//     }
//     Point& operator=(const Point& pt)
//     {
//         this->x = pt.getX();
//         this->y = pt.getY();
//         return *this;
//     }
// };

// int main() {
// 	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
// 	Point* pP1;
//     Point* pP2;
//     Point* pP3;

// 	cout << "첫번째 좌표(x1, y1)를 입력하세요 : ";
// 	cin >> x1 >> y1;

// 	cout << "두번째 좌표(x2, y2)를 입력하세요 : ";
// 	cin >> x2 >> y2;

// 	pP1 = new Point(x1, y1);
// 	pP2 = new Point(x2, y2);
// 	pP3 = new Point(); //x,y가 0으로 초기화

// 	/* 아래의 방식으로도 x, y값 설정이 가능해야 함 */
// 	// pP1->setPoint(x1, y1);
//     // pP2->setPoint(x2, y2);
    
//     cout << pP1->getX() << " " << pP1->getY() << endl;
//     cout << pP2->getX() << " " << pP2->getY() << endl;
// 	/***********************************************/

// 	*pP3 = (*pP1 - *pP2) * (*pP1 - *pP2);

// 	/* pP3을 활용하여 거리값을 구함 */
// 	cout << "두 좌표 사이의 길이는 " << pP3->square() << "입니다." << endl;

//     delete pP1; 
//     delete pP2;
//     delete pP3;

// 	return 0;
// }


// #include<iostream>
// #include<string>

// using namespace std;

// class Account {
//     private:
//         string name;
//         string id;
//         int balance;
    
//     public:
//         Account(string _name, string _id, int _balance): name(_name), id(_id), balance(_balance) {};

//         string getName() const
//         {
//             return this->name;
//         }
//         string getId() const
//         {
//             return this->id;
//         }
//         int getBalance() const
//         {
//             return this->balance;
//         }
//         Account operator+(const Account& account)
//         {
//             Account result(this->name, this->id, this->balance + account.getBalance());
//             return result;
//         }
//         Account operator-(const Account& account)
//         {
//             Account result(this->name, this->id, this->balance - account.getBalance());
//             return result;
//         }
//         Account& operator=(const Account& account)
//         {
//             this->name = account.getName();
//             this->id = account.getId();
//             this->balance = account.getBalance();

//             return *this;
//         }
//         friend ostream& operator<<(ostream& cout, Account& account)
//         {
//             return cout << "학번: " << account.getId() << ", 이름: " << account.getName() << ", 잔액: " << account.getBalance() << endl;
//         }
// };

// int main() {
// 	Account acnt[3] = {
// 		Account("장윤호", "2014", 10000),
// 		Account("김유민", "2019", 0),
// 		Account("박진배", "2013", 5000),
// 	};

//     string sendId, recvId;
//     int sendIndex, recvIndex;

//     while(1)
//     {
//         sendIndex = recvIndex = -1;
//         cout << "돈을 보낼 학생의 학번을 입력하세요: ";
//         cin >> sendId;
//         if(sendId == "종료")
//         {
//             cout << "종료합니다." << endl;
//             break;
//         }
//         cout << "돈을 받을 학생의 학번을 입력하세요: ";
//         cin >> recvId;
//         if(sendId == recvId)
//         {
//             cout << "학번이 동일합니다." << endl;
//             continue;
//         }
//         for(int i = 0; i < 3; i++)
//         {
//             if(acnt[i].getId() == sendId)
//                 sendIndex = i;
//             else if(acnt[i].getId() == recvId)
//                 recvIndex = i;
//         }
//         if(sendIndex == -1 || recvIndex == -1)
//         {
//             cout << "보내는 학생 혹은 받는 학생의 학번이 존재하지 않습니다.다시 입력해주세요." << endl;
//             continue;
//         }
//         if(acnt[sendIndex].getBalance() <= 0)
//         {
//             cout << "보내는 학생의 잔액이 부족합니다." << endl;
//             continue;
//         }
//         acnt[recvIndex] = acnt[recvIndex] + acnt[sendIndex];
//         acnt[sendIndex] = acnt[sendIndex] - acnt[sendIndex];

//         cout << "보낸 학생의 잔액 => " << acnt[sendIndex];
//         cout << "받은 학생의 잔액 => " << acnt[recvIndex];
//     }

//     for(int i = 0; i < 3; i++)
//         cout << acnt[i];

//     return 0;
// }


// #include<iostream>
// #include<string>

// using namespace std;

// class Account {
//     private: 
//         string id;
//         string name;
//         int balance;
//     public:
//         Account(string _id, string _name, int _balance): id(_id), name(_name), balance(_balance) {}
//         Account(): id(""), name(""), balance(0){}
//         string getId() const {
//             return this->id;
//         }
//         string getName() const {
//             return this->name;
//         }
//         int getBalance() const {
//             return this->balance;
//         }
//         void setId(string id)
//         {
//             this->id = id;
//         }
//         void setName(string name)
//         {
//             this->name = name;
//         }
//         void setBalance(int balance)
//         {
//             this->balance = balance;
//         }

// };

// int main(void)
// {
//     int n, balance, sum = 0;
//     string id, name;
//     bool flag;
//     cout << "총 학생 수 입력: ";
//     cin >> n;

//     Account *account = new Account[n];

//     for(int i = 0; i < n; i++)
//     {
//         flag = false;
//         cout << i + 1 << "번째 학생 계좌 입력 : " << endl;
//         cout << "학번 : ";
//         cin >> id;
//         cout << endl;
//         cout << "이름 : ";
//         cin >> name;
//         cout << endl;
//         cout << "잔액 : ";
//         cin >> balance;
//         cout << "======================" << endl << endl;

//         if(i != 0)
//         {
//             for(int j = 0; j < i; j++)
//             {
//                 if(account[j].getId() == id || account[j].getName() == name || account[j].getBalance() == balance)
//                     flag = true;
//             }
//         }

//         if(flag)
//             exit(-1);

//         account[i].setId(id);
//         account[i].setName(name);
//         account[i].setBalance(balance);
//     } 

//     for(int i = 0; i < n; i++)
//         sum += account[i].getBalance();
//     cout << "회수된 금액 : " << sum << endl;

//     delete[] account;

//     return 0;
// }
#include <iostream>
#include<string>
using namespace std;

struct Contact {
	string address;
	string phoneNumber;
	string gender;
	string name;
};

Contact con[100];
int contactCount = 0;
Contact myInfo;

void showMenus() {
	cout << "\n=====通讯录=====" << endl;
	cout << "1.我的名片" << endl;
	cout << "2.增加联系人" << endl;
	cout << "3.删除联系人" << endl;
	cout << "4.查找联系人" << endl;
	cout << "5.修改联系人" << endl;
	cout << "6.显示联系人" << endl;
	cout << "7.清空所有联系人" << endl;
	cout << "0.退出通讯录" << endl;
}

void addContact() {
	//清空缓冲区残留的换行符
	cin.ignore();
	// 功能：添加联系人信息到通讯录数组
// 操作：获取用户输入的姓名、电话、性别、地址等信息，
//      并将其存入联系人数组 con 中，同时更新联系人数量 contactCount
	cout << "请输入联系人姓名:" << endl;
	getline(cin,con[contactCount].name);
	cout << "请输入联系人电话：" << endl;
	getline(cin, con[contactCount].phoneNumber);
	cout << "请输入联系人性别：" << endl;
	getline(cin, con[contactCount].gender);
	cout << "请输入联系人地址:" << endl;
	getline(cin, con[contactCount].address);
	contactCount++;
	cout << "联系人添加成功！" << endl;
}

void showContacts() {
	if (contactCount == 0) {
		cout << "通讯里为空" << endl;
		return;
	}
	cout << "\n=====所有联系人列表=====" << endl;
	for (int i = 0;i < contactCount;i++) {
		cout << "姓名：" << con[i].name << endl;
		cout << "电话：" << con[i].phoneNumber << endl;
		cout << "性别：" << con[i].gender << endl;
		cout << "地址：" << con[i].address << endl;
			cout << "----------------------" << endl;
	}
}

void deleteContact() {
	// 功能：从通讯录中删除指定姓名的联系人
		// 操作：通过遍历联系人数组 con，查找与输入姓名匹配的联系人，
		//      若找到则将其后的联系人向前移动覆盖，更新联系人数量 contactCount，
		//      若未找到则提示查询失败
	string name;
	cin.ignore();
	bool found = false;
	cout << "请输入姓名：" << endl;
	getline(cin, name);
	for (int i = 0;i < contactCount;i++) {
		if (con[i].name == name) {
			for (int j = i;j < contactCount - 1;j++) {
				con[j] = con[j + 1];
			}
			contactCount--;
			found = true;
			cout << "删除成功！" << endl;
			break;
		}
		}
	if (!found) {
		cout << "查询失败,未找到该联系人！" << endl;
	}
}

void editContact() {
	string name;
	cin.ignore();
	cout << "请输入联系人姓名：" << endl;
	getline(cin, name);
	bool found = false;
	for (int i = 0;i < contactCount;i++) {
		if (con[i].name == name) {
			found = true;
			cout << "联系人存在，是否要修改信息？(1-是 0-否）" << endl;
			int choice = 0;
			cin >> choice;
			if (choice!= 1) {
				cout << "已取消修改" << endl;
				break;
			}
			while (true) {
				cout << "\n=====请选择要修改的内容=====" << endl;
				cout << "1.修改姓名" << endl;
				cout << "2.修改电话" << endl;
				cout << "3.修改性别" << endl;
				cout << "4.修改地址" << endl;
				cout << "0.修改完成，退出" << endl;
			
			int op = 0;
			cin >> op;
			cin.ignore();
			switch (op) {
			case 1:
				cout << "请输入姓名：" << endl;
				getline(cin, con[i].name);
				cout << "姓名修改完成" << endl;
				break;
			case 2:
				cout << "请输入电话：" << endl;
				getline(cin, con[i].phoneNumber);
				cout << "电话修改完成" << endl;
				break;
			case 3:
				cout << "请输入性别：" << endl;
				getline(cin, con[i].gender);
				cout << "性别修改完成" << endl;
				break;
			case 4:
				cout << "请输入地址：" << endl;
				getline(cin, con[i].address);
				cout << "地址修改完成" << endl;
				break;
			case 0:
				cout << "修改完成，返回主菜单！" << endl;
				return;
			default:
				cout << "请输入0-4的数字" << endl;
				break;
				
			}
			}
		}
		}
	if (!found) {
		cout << "未找到该联系人！" << endl;
	}

}

void showMyInfo() {
	cout << "\n===== 你的个人信息 =====\n";
	cout << "姓名：" << myInfo.name << endl;
	cout << "电话：" << myInfo.phoneNumber << endl;
	cout << "性别：" << myInfo.gender<< endl;
	cout << "地址：" << myInfo.address << endl;
	cout << "=======================\n";
}

void myInformation() {
	cin.ignore();
	cout << "请输入姓名：" << endl;
	getline(cin, myInfo.name);
	cout << "请输入电话：" << endl;
	getline(cin, myInfo.phoneNumber);
	cout << "请输入性别：" << endl;
	getline(cin, myInfo.gender);
	cout << "请输入地址：" << endl;
	getline(cin, myInfo.address);
	cout << "个人信息已保存！" << endl;
	showMyInfo();
}

void findContact() {
	string name;
	bool found = false;
	cin.ignore();
	cout << "请输入联系人姓名" << endl;
	getline(cin, name);
	for (int i = 0;i < contactCount;i++) {
		if (con[i].name == name) {
			found = true;
			cout << "该联系人存在！" << endl;
			cout << "\n找到联系人！信息如下：" << endl;
			cout << "姓名：" << con[i].name << endl;
			cout << "电话：" << con[i].phoneNumber << endl;
			cout << "性别：" << con[i].gender << endl;
			cout << "地址：" << con[i].address << endl;
			cout << "-------------------------" << endl;
		}
		}
	if (!found) {
		cout << "该联系人不存在！" << endl;
	}
}

void clearAllContact() {
	if (contactCount == 0) {
		cout << "通讯录为空，无须清除！" << endl;
		return;
	}
	cout << "⚠确定要清除所有联系人吗？（y/n)" << endl;
	char confirm;
	cin >> confirm;
	if (confirm == 'y' || confirm == 'Y') {
		contactCount = 0;
		cout << "通讯录已清空" << endl;
	}
	else if(confirm=='n' || confirm == 'N') {
		cout << "已取消该操作" << endl;
		return;
	}
	else {
		cout << "输入无效，已取消操作" << endl;
	}
}

int main() {
	int choice = 0;
	do {
		showMenus();
		cin >> choice;

		switch (choice) {
		case 1:
			myInformation();
			break;
		case 2:
			addContact();
			break;
		case 3:
			deleteContact();
			break;
		case 4:
			findContact();
			break;
		case 5:
			editContact();
			break;
		case 6:
			showContacts();
			break;
		case 7:
			clearAllContact();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "请输入0到7的数字" << endl;
			break;
		}

		if (choice != 0) {
			cout << "按任意键继续......" << endl;
			cin.ignore();
			cin.get();//暂时停住，等我按任意键后再次打开菜单
		}

	}
	while (choice != 0);
	
		return 0;
	}

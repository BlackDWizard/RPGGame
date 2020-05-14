#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <stdlib.h>
#include <direct.h>
#include <io.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAXBARLEN 40
string true_account = "user";
string true_password = "user";



class worldMap {
public:

	int birthPosition = 3;
	int position = birthPosition;

	vector<int>regionId;
	vector<string>regionName;
	vector<string> regionDescribe;
};

class monster {
public:
	string name;
	int strength;
	int hp = 100;
	int maxHp = 100;
	int atk = 100;

	monster(int strength, string name, int hp, int atk);
};

class map {
public:

	unsigned int randnum_monster1 = rand() % 25;
	unsigned int randnum_monster2 = rand() % 25;
	unsigned int randnum_monster3 = rand() % 25;
	unsigned int randnum_monster4 = rand() % 25;
	unsigned int randnum_monster5 = rand() % 25;

	int count = 0;
	int shop_active = 0;
	int item_menu = 0;

	vector<int>randomVector;
	vector<int>weaponId;
	vector<int>armorId;
	vector<int>poisonId;
	vector<int>foodId;
	vector<int>skillId;
	vector<int>weaponPlus;
	vector<int>armorPlus;
	vector<int>poisonPlus;
	vector<int>foodPlus;
	vector<int>skillPlus;
	vector<int>skillCost;

	vector<string>weaponName;
	vector<string>armorName;
	vector<string>poisonName;
	vector<string>foodName;
	vector<string>skillName;

	vector<int>monster_x;
	vector<int>monster_y;

	int chtr_location_x = 20;
	int chtr_location_y = 10;

	void town_initialize() {
		for (int i = 0; i <= 20; i++) {
			for (int j = 0; j <= 40; j++) {

				if (j == chtr_location_x && i == chtr_location_y) {
					cout << '*';
				}
				else if (i % 4 == 0)
					cout << "-";
				else if (j % 8 == 0)
					cout << "|";
				else if (i == 2 && j == 4)
					cout << "W";
				else if (i == 10 && j == 12)
					cout << "A";
				else if (i == 14 && j == 28)
					cout << "F";
				else if (i == 6 && j == 28)
					cout << "P";
				else if (i == 18 && j == 12)
					cout << "B";
				else
					cout << " ";
			}
			cout << "\n";
		}
		cout << "W:武器店, A:防具店, F:食物攤, P:藥水鋪, B:全補站" << endl << endl;

		if (chtr_location_x == 4 && chtr_location_y == 2) {
			cout << "武器店，請問是否入內採購？" << endl;
			item_menu = 1;
		}
		else if (chtr_location_x == 12 && chtr_location_y == 10) {
			cout << "頭部防具店，請問是否入內採購？" << endl;
			item_menu = 2;
		}
		else if (chtr_location_x == 28 && chtr_location_y == 14) {
			cout << "食物攤，請問是否入內採購？" << endl;
			item_menu = 3;
		}
		else if (chtr_location_x == 28 && chtr_location_y == 6) {
			cout << "藥水鋪，請問是否入內採購？" << endl;
			item_menu = 4;
		}
		else if (chtr_location_x == 12 && chtr_location_y == 18) {
			cout << "全補站，請問是否補滿HP/MP？" << endl;
			item_menu = 5;
		}

	};

	vector<monster> normal_initialize(vector<monster>monsterEasyBuffer, vector<monster>monsterMiddleBuffer, vector<monster>monsterHardList) {
		monster_x.clear();
		monster_y.clear();
		vector<monster>totalMst;
		vector<int>totalMstPositionX;
		vector<int>totalMstPositionY;
		for (int i = 0; i <= 20; i++) {
			for (int j = 0; j <= 40; j++) {
				if (i == ((randnum_monster1 / 5) * 4 + 2) && j == ((randnum_monster2 / 5) * 8 + 4)) {
					totalMst.push_back(monsterEasyBuffer[randnum_monster1 / 8]);
					totalMstPositionX.push_back((j - 4) / 8);
					totalMstPositionY.push_back((i - 2) / 4);
					cout << "_";
				}
				else if (i == ((randnum_monster2 / 5) * 4 + 2) && j == ((randnum_monster3 / 5) * 8 + 4)) {
					totalMst.push_back(monsterEasyBuffer[randnum_monster2 / 8]);
					totalMstPositionX.push_back((j - 4) / 8);
					totalMstPositionY.push_back((i - 2) / 4);
					cout << "_";
				}
				else if (i == ((randnum_monster3 / 5) * 4 + 2) && j == ((randnum_monster4 / 5) * 8 + 4)) {
					totalMst.push_back(monsterMiddleBuffer[randnum_monster3 / 24]);
					totalMstPositionX.push_back((j - 4) / 8);
					totalMstPositionY.push_back((i - 2) / 4);
					cout << "-";
				}
				else if (i == ((randnum_monster4 / 5) * 4 + 2) && j == ((randnum_monster5 / 5) * 8 + 4)) {
					totalMst.push_back(monsterMiddleBuffer[randnum_monster4 / 24]);
					totalMstPositionX.push_back((j - 4) / 8);
					totalMstPositionY.push_back((i - 2) / 4);
					cout << "-";
				}
				else if (i == ((randnum_monster5 / 5) * 4 + 2) && j == ((randnum_monster1 / 5) * 8 + 4)) {
					totalMst.push_back(monsterHardList[randnum_monster5 / 8]);
					totalMstPositionX.push_back((j - 4) / 8);
					totalMstPositionY.push_back((i - 2) / 4);
					cout << "@";
				}
				else if (j == chtr_location_x && i == chtr_location_y) {
					cout << '*';
				}
				else if (i % 4 == 0)
					cout << "-";
				else if (j % 8 == 0)
					cout << "|";
				else
					cout << " ";
			}
			cout << "\n";
		}
		cout << "勇者當前位置:(" << (chtr_location_x - 4) / 8 << "," << (chtr_location_y - 2) / 4 << ")" << endl;
		cout << "當前存在怪物 : " << endl;
		for (int i = 0; i < totalMst.size(); i++) {
			cout << i + 1 << ". " << totalMst[i].name << " 等級 : " << totalMst[i].strength <<
				" 血量 :" << totalMst[i].hp << " 攻擊力 :" << totalMst[i].atk
				<< " 位置：(" << totalMstPositionX[i] << "," << totalMstPositionY[i] << ")" << endl;
		}
		monster_x = totalMstPositionX;
		monster_y = totalMstPositionY;
		return totalMst;
	};

};

class charactor {
public:

	int hp = 100;
	int mp = 100;
	int atk = 10;
	int maxHp = 100;
	int maxMp = 100;
	int exp = 0;
	int level = 1;
	int levelExp = 100;
	int coin = 0;
	vector<string>bag;
	char movement;

private:

};

class skill {
public:
	string skillName;
	int skillPlus;
	int skillLevel = 1;
	int skillExp = 0;
	int skillCost;
};

class item {
public:
	string itemName;
	int itemPlus;
	bool operator==(const item& y);
};

bool item::operator==(const item& y) {
	return((itemName == y.itemName) || (itemPlus == y.itemPlus));
}

monster::monster(int bufferStrength, string bufferName, int bufferHp, int bufferAtk)
{
	name = bufferName;
	strength = bufferStrength;
	hp = bufferHp;
	atk = bufferAtk;
}

vector<string>player;


void randomMstPdc(map mapBuffer) {
	mapBuffer.randomVector.clear();
	for (int i = 0; i < mapBuffer.randomVector.size(); i++)
	{
		mapBuffer.randnum_monster1 = rand() % 25;
		mapBuffer.randnum_monster2 = rand() % 25;
		mapBuffer.randnum_monster3 = rand() % 25;
		mapBuffer.randnum_monster4 = rand() % 25;
		mapBuffer.randnum_monster5 = rand() % 25;
		mapBuffer.randomVector.push_back(mapBuffer.randnum_monster1);   //亂數產生，亂數產生的範圍是1~9
		mapBuffer.randomVector.push_back(mapBuffer.randnum_monster2);   //亂數產生，亂數產生的範圍是1~9
		mapBuffer.randomVector.push_back(mapBuffer.randnum_monster3);   //亂數產生，亂數產生的範圍是1~9
		mapBuffer.randomVector.push_back(mapBuffer.randnum_monster4);   //亂數產生，亂數產生的範圍是1~9
		mapBuffer.randomVector.push_back(mapBuffer.randnum_monster5);   //亂數產生，亂數產生的範圍是1~9

		for (int j = 0; j < i; j++)
		{
			while (mapBuffer.randomVector[j] == mapBuffer.randomVector[i])    //檢查是否與前面產生的數值發生重複，如果有就重新產生
			{
				j = 0;  //如有重複，將變數j設為0，再次檢查 (因為還是有重複的可能)
				mapBuffer.randomVector[i] = rand() % 25;   //重新產生，存回陣列，亂數產生的範圍是1~9
			}
		}
	}
};

double log2_log(double x)
{
	return log(x) / log(2.0);
}

class dataSaved {
public:
	int chtrLvl;
	int chtrHp;
	int chtrMp;
	int chtrAtk;
	int chtrCoin;
	int chtrExp;
	int chtrSkill1Lvl;
	int chtrSkill1Exp;
	int chtrSkill2Lvl;
	int chtrSkill2Exp;
	int chtrSkill3Lvl;
	int chtrSkill3Exp;
	int chtrSkill4Lvl;
	int chtrSkill4Exp;
	int chtrSkill5Lvl;
	int chtrSkill5Exp;
	vector<string>savedBag;
};

int main() {

	system("mode con cols=180 lines=35");

	ifstream finPlayer;
	ifstream finBag;
	ifstream fin;
	ifstream finWeapon;
	ifstream finArmor;
	ifstream finPoison;
	ifstream finFood;
	ifstream finMap;
	ifstream finMonster;
	ifstream finSkill;

	unsigned int randomItem = rand() % 20;
	unsigned int randomExp = rand() % 50 + 10;
	unsigned int randomCoin = rand() % 20 + 5;

	int chtr_num, regionIdTmp, weaponIdTmp, armorIdTmp, foodIdTmp, poisonIdTmp, mstIdTmp, mstLvlTmp, skillIdTmp;
	int weaponPlusTmp, armorPlusTmp, poisonPlusTmp, foodPlusTmp, skillPlusTmp, skillCostTmp;
	int name_count = 0;
	int fightscene = 0;
	int currentMosterX;
	int currentMosterY;
	int currentMonsterVectorPosition;
	int currentMonsterVectorPositionBuffer;

	int loadDataAtk;
	int loadDataMaxHp;
	int loadDataMaxMp;
	int loadDataLevel;
	int loadDataCoin;
	int loadDataExp;
	int loadDataSkill1Lvl;
	int loadDataSkill1Exp;
	int loadDataSkill2Lvl;
	int loadDataSkill2Exp;
	int loadDataSkill3Lvl;
	int loadDataSkill3Exp;
	int loadDataSkill4Lvl;
	int loadDataSkill4Exp;
	int loadDataSkill5Lvl;
	int loadDataSkill5Exp;

	string loadDataBagBuffer;

	vector<string>loadDataBag;


	string command_chtr, command, account_number, password, chtr_name, str1, regionNameTmp, regionDescribeTmp;
	string weaponNameTmp, armorNameTmp, poisonNameTmp, foodNameTmp, skillNameTmp;
	string mstNameTmp;


	char path[_MAX_PATH]; // _MAX_PATH is defined in windows.h	

	cout << "請選擇登入(sign)或離開(exit) : ";
	cin >> command;

	while (1) {
		if (command == "sign") {
			if ((_access("C:\\gameDataFolder", 0)) != -1) {
				cout << "Folder 'gameDataFolder' exists, please enter your account number and password.\n";
				while (account_number != true_account || password != true_password) {
					cout << "account : ";
					cin >> account_number;
					cout << "password : ";
					cin >> password;
					if (account_number != true_account || password != true_password)
						cout << "error!\n";
				}
				cout << "account correct!" << endl;
				break;
			}
			else {
				string defaultPath = "C:";
				string folderPath = defaultPath + "\\gameDataFolder";
				string command;
				command = "mkdir -p " + folderPath;
				system(command.c_str());
				break;
			}
		}
		else if (command == "exit")
			return 0;
		else {
			cout << "No such command!\n";
			cout << "請選擇登入(sign)或離開(exit) : ";
			cin >> command;
		}
	}
	HANDLE hFind;
	WIN32_FIND_DATA FindFileData;
	charactor chtr;
	vector<skill>chtrSkillList;//加入

	if ((hFind = FindFirstFileA("C:\\gameDataFolder\\*.*", &FindFileData)) != INVALID_HANDLE_VALUE)
	{
		BOOL bFind = TRUE;
		BOOL EmptyDirectory = TRUE;
		while (bFind)
		{
			if (strcmp(FindFileData.cFileName, ".") == 0
				|| strcmp(FindFileData.cFileName, "..") == 0)
			{
				bFind = FindNextFile(hFind, &FindFileData);
			}
			else
			{
				EmptyDirectory = FALSE;
				break;
			}
		}
		if (EmptyDirectory)
		{
			cout << "新遊戲!" << endl;
		}
		else
		{
			cout << "請問要繼續遊戲嗎? ( 1:是/2:否 )" << endl;
			int start = 0;
			cin >> start;
			if (start == 1) {


				finBag.open("C:\\gameDataFolder\\bag.txt");
				finPlayer.open("C:\\gameDataFolder\\player.txt");

				while (finPlayer >> loadDataLevel >> loadDataMaxHp >> loadDataMaxMp >> loadDataAtk
					>> loadDataCoin >> loadDataExp >>
					loadDataSkill1Lvl >> loadDataSkill1Exp >> loadDataSkill2Lvl >> loadDataSkill2Exp >> loadDataSkill3Lvl >>
					loadDataSkill3Exp >> loadDataSkill4Lvl >> loadDataSkill4Exp >> loadDataSkill5Lvl >> loadDataSkill5Exp) {
					chtr.atk = loadDataAtk;
					chtr.maxHp = loadDataMaxHp;
					chtr.maxMp = loadDataMaxMp;
					chtr.level = loadDataLevel;
					chtr.coin = loadDataCoin;
					chtr.exp = loadDataExp;
					for (int i = 0; i < 5; i++) {
						skill skillBuffer;
					}

				}
				while (finBag >> loadDataBagBuffer) {
					loadDataBag.push_back(loadDataBagBuffer);
				}

				chtr.bag = loadDataBag;
			}
		}
	}
	else
	{
		cout << "Path does not exist." << endl;
	}

	worldMap worldMap;
	map map;

	finMap.open("worldMap.txt");
	while (finMap >> regionIdTmp >> regionNameTmp >> regionDescribeTmp) {
		worldMap.regionId.push_back(regionIdTmp);
		worldMap.regionName.push_back(regionNameTmp);
		worldMap.regionDescribe.push_back(regionDescribeTmp);
	}

	finWeapon.open("weapon.txt");
	while (finWeapon >> weaponIdTmp >> weaponNameTmp >> weaponPlusTmp) {
		map.weaponId.push_back(weaponIdTmp);
		map.weaponName.push_back(weaponNameTmp);
		map.weaponPlus.push_back(weaponPlusTmp);
	}

	finArmor.open("armor.txt");
	while (finArmor >> armorIdTmp >> armorNameTmp >> armorPlusTmp) {
		map.armorId.push_back(armorIdTmp);
		map.armorName.push_back(armorNameTmp);
		map.armorPlus.push_back(armorPlusTmp);
	}

	finFood.open("food.txt");
	while (finFood >> foodIdTmp >> foodNameTmp >> foodPlusTmp) {
		map.foodId.push_back(foodIdTmp);
		map.foodName.push_back(foodNameTmp);
		map.foodPlus.push_back(foodPlusTmp);
	}

	finPoison.open("poison.txt");
	while (finPoison >> poisonIdTmp >> poisonNameTmp >> poisonPlusTmp) {
		map.poisonId.push_back(poisonIdTmp);
		map.poisonName.push_back(poisonNameTmp);
		map.poisonPlus.push_back(poisonPlusTmp);
	}

	finSkill.open("skill.txt");
	while (finSkill >> skillIdTmp >> skillNameTmp >> skillPlusTmp >> skillCostTmp) {
		skill chtrSkill;
		chtrSkill.skillName = skillNameTmp;
		chtrSkill.skillPlus = skillPlusTmp;
		chtrSkill.skillCost = skillCostTmp;
		chtrSkillList.push_back(chtrSkill);

		map.skillId.push_back(skillIdTmp);
		map.skillName.push_back(skillNameTmp);
		map.skillPlus.push_back(skillPlusTmp);
		map.skillCost.push_back(skillCostTmp);
	}

	vector<string>allItemNameBuffer;
	allItemNameBuffer.insert(allItemNameBuffer.end(), map.weaponName.begin(), map.weaponName.end());
	allItemNameBuffer.insert(allItemNameBuffer.end(), map.armorName.begin(), map.armorName.end());
	allItemNameBuffer.insert(allItemNameBuffer.end(), map.poisonName.begin(), map.poisonName.end());
	allItemNameBuffer.insert(allItemNameBuffer.end(), map.foodName.begin(), map.foodName.end());

	vector<int>allItemPlusBuffer;
	allItemPlusBuffer.insert(allItemPlusBuffer.end(), map.weaponPlus.begin(), map.weaponPlus.end());
	allItemPlusBuffer.insert(allItemPlusBuffer.end(), map.armorPlus.begin(), map.armorPlus.end());
	allItemPlusBuffer.insert(allItemPlusBuffer.end(), map.poisonPlus.begin(), map.poisonPlus.end());
	allItemPlusBuffer.insert(allItemPlusBuffer.end(), map.foodPlus.begin(), map.foodPlus.end());

	vector<item>allItemList;

	for (int i = 0; i < allItemNameBuffer.size(); i++) {
		item itemtmp;
		allItemList.push_back(itemtmp);
	}
	for (int i = 0; i < allItemNameBuffer.size(); i++) {
		allItemList[i].itemName = allItemNameBuffer[i];
		allItemList[i].itemPlus = allItemPlusBuffer[i];
	}

	vector<monster>mstWeakList;
	vector<monster>mstMiddleList;
	vector<monster>mstHardList;
	vector<monster>mstTotalList;

	finMonster.open("monster.txt");
	while (finMonster >> mstIdTmp >> mstNameTmp >> mstLvlTmp) {
		monster mstTmp(mstLvlTmp, mstNameTmp, 100, 100);
		if (mstLvlTmp < 5) {
			mstTmp.hp = 0.3*mstTmp.hp;
			mstTmp.atk = 0.05*mstTmp.atk;
			mstWeakList.push_back(mstTmp);
		}
		else if (mstLvlTmp >= 5 && mstLvlTmp < 10) {
			mstTmp.hp = 0.7*mstTmp.hp;
			mstTmp.atk = 0.15*mstTmp.atk;
			mstMiddleList.push_back(mstTmp);
		}
		else {
			mstTmp.hp = mstTmp.hp;
			mstTmp.atk = 0.45*mstTmp.atk;
			mstHardList.push_back(mstTmp);
		}

	}

	map.town_initialize();
	cout << "請輸入指令(w:上/s:下/a:左/d:右/e:互動/k:打架/c:人物狀態/m:世界地圖/b:打開背包/f:離開):";
	cin >> chtr.movement;

	while (chtr.movement != 'o') {
		srand((unsigned int)time(NULL));
		system("cls");
		currentMonsterVectorPosition = 0;
		switch (chtr.movement) {

		case 'w':
			if (map.chtr_location_y <= 2) {
				map.chtr_location_y = map.chtr_location_y + 16;
				if ((worldMap.position == 1) || (worldMap.position == 2) || (worldMap.position == 4)) {
					map.chtr_location_y = map.chtr_location_y - 16;
					cout << "超出地圖邊界請往回移動" << endl;
				}
				else {
					worldMap.position = worldMap.position - 2;

					map.randnum_monster1 = rand() % 25;
					map.randnum_monster2 = rand() % 25;
					map.randnum_monster3 = rand() % 25;
					map.randnum_monster4 = rand() % 25;
					map.randnum_monster5 = rand() % 25;
					randomMstPdc(map);
				}


			}
			else {
				map.chtr_location_y = map.chtr_location_y - 4;
			}
			break;
		case 's':
			if (map.chtr_location_y >= 18) {
				map.chtr_location_y = map.chtr_location_y - 16;
				if ((worldMap.position == 5) || (worldMap.position == 2) || (worldMap.position == 4)) {
					map.chtr_location_y = map.chtr_location_y + 16;
					cout << "超出地圖邊界請往回移動" << endl;
				}
				else {
					worldMap.position = worldMap.position + 2;

					map.randnum_monster1 = rand() % 25;
					map.randnum_monster2 = rand() % 25;
					map.randnum_monster3 = rand() % 25;
					map.randnum_monster4 = rand() % 25;
					map.randnum_monster5 = rand() % 25;
					randomMstPdc(map);
				}
			}
			else {
				map.chtr_location_y = map.chtr_location_y + 4;
			}
			break;
		case 'a':
			if (map.chtr_location_x <= 4) {
				map.chtr_location_x = map.chtr_location_x + 32;
				if ((worldMap.position == 1) || (worldMap.position == 2) || (worldMap.position == 5)) {
					map.chtr_location_x = map.chtr_location_x - 32;
					cout << "超出地圖邊界請往回移動" << endl;
				}
				else {
					worldMap.position = worldMap.position - 1;
					map.randnum_monster1 = rand() % 25;
					map.randnum_monster2 = rand() % 25;
					map.randnum_monster3 = rand() % 25;
					map.randnum_monster4 = rand() % 25;
					map.randnum_monster5 = rand() % 25;
					randomMstPdc(map);
				}

			}
			else {
				map.chtr_location_x = map.chtr_location_x - 8;
			}
			break;
		case 'd':
			if (map.chtr_location_x >= 36) {
				map.chtr_location_x = map.chtr_location_x - 32;
				if ((worldMap.position == 1) || (worldMap.position == 4) || (worldMap.position == 5)) {
					map.chtr_location_x = map.chtr_location_x + 32;
					cout << "超出地圖邊界請往回移動" << endl;
				}
				else {
					worldMap.position = worldMap.position + 1;
					map.randnum_monster1 = rand() % 25;
					map.randnum_monster2 = rand() % 25;
					map.randnum_monster3 = rand() % 25;
					map.randnum_monster4 = rand() % 25;
					map.randnum_monster5 = rand() % 25;
					randomMstPdc(map);
				}
			}
			else {
				map.chtr_location_x = map.chtr_location_x + 8;
			}
			break;
		case 'm':
			cout << "當前所在位置 : " << worldMap.regionName[worldMap.position - 1];
			cout << "當前所在位置 : " << worldMap.regionId[worldMap.position - 1];
			cout << endl << endl;
			break;

		case 'e': {
			if ((worldMap.position - 1) == 2) {
				switch (map.item_menu) {
				case 1: {
					cout << "物品列表 : " << endl;
					for (int i = 0; i < map.weaponName.size(); i++) {
						cout << i + 1 << "." << map.weaponName[i] << "\t\t價格 : " << map.weaponPlus[i];
						cout << endl;
					}
					int purchaseChoice = 0;
					cout << "請問要購買哪項 ? (0:離開)";
					cin >> purchaseChoice;
					if (purchaseChoice == 0)
						break;
					while (purchaseChoice <= 0 || purchaseChoice > map.weaponId.size()) {
						cout << "無此選項!!請重新選擇：";
						cin >> purchaseChoice;
					}
					string itemName = map.weaponName[purchaseChoice - 1];
					vector<string>::iterator it = find(map.weaponName.begin(), map.weaponName.end(), itemName);
					if (it != map.weaponName.end()) {
						int itemPosition = distance(map.weaponName.begin(), it);
						if (itemPosition >= 0 && itemPosition < 5) {
							//cout << "武器" << endl;
							int purchaseConfirm = 0;
							if (chtr.coin > map.weaponPlus[itemPosition]) {
								cout << "確認購買嗎? 1: 是 / 2: 否" << endl;
								cin >> purchaseConfirm;
								if (purchaseConfirm == 1) {
									chtr.bag.push_back(map.weaponName[itemPosition]);
								}
								else {
									break;
								}
							}
							else {
								cout << "你擁有的金幣不足，請再接再厲。" << endl;
								break;
							}
							int equipConfirm = 0;
							cout << "請問要馬上裝備嗎? 1:是 / 2:否" << endl;
							cout << "裝備前攻擊力 : " << chtr.atk << endl;
							cout << "裝備後攻擊力 : " << chtr.atk + map.weaponPlus[itemPosition] << endl;
							cin >> equipConfirm;
							if (equipConfirm == 1) {
								chtr.atk += map.weaponPlus[itemPosition];
							}
						}
					}
					break;
				}
				case 2: {
					cout << "物品列表 : " << endl;
					for (int i = 0; i < map.armorName.size(); i++) {
						cout << i + 1 << "." << map.armorName[i] << "\t\t價格 : " << map.armorPlus[i];
						cout << endl;
					}
					int purchaseChoice = 0;
					cout << "請問要購買哪項 ? (0:離開)";
					cin >> purchaseChoice;
					if (purchaseChoice == 0)
						break;
					while (purchaseChoice < 0 || purchaseChoice > map.armorId.size()) {
						cout << "無此選項!!請重新選擇：";
						cin >> purchaseChoice;
					}
					string itemName = map.armorName[purchaseChoice - 1];
					vector<string>::iterator it = find(map.armorName.begin(), map.armorName.end(), itemName);
					if (it != map.armorName.end()) {
						int itemPosition = distance(map.armorName.begin(), it);
						if (itemPosition >= 0 && itemPosition < 5) {
							//cout << "防具" << endl;
							int purchaseConfirm = 0;
							if (chtr.coin > map.armorPlus[itemPosition]) {
								cout << "確認購買嗎? 1: 是 / 2: 否";
								cin >> purchaseConfirm;
								if (purchaseConfirm == 1) {
									chtr.bag.push_back(map.armorName[itemPosition]);
								}
								else {
									break;
								}
							}
							else {
								cout << "你擁有的金幣不足，請再接再厲。" << endl;
								break;
							}
							int equipConfirm = 0;
							cout << "請問要馬上裝備嗎? 1:是 / 2:否" << endl;
							cout << "裝備前最大生命值 : " << chtr.maxHp << endl;
							cout << "裝備後最大生命值 : " << chtr.maxHp + map.armorPlus[itemPosition] << endl;
							cin >> equipConfirm;
							if (equipConfirm == 1) {
								chtr.maxHp += map.armorPlus[itemPosition];
							}
						}
					}
					break;
				}
				case 3: {
					cout << "物品列表 : " << endl;
					for (int i = 0; i < map.foodName.size(); i++) {
						cout << i + 1 << "." << map.foodName[i] << "\t\t價格 : " << map.foodPlus[i];
						cout << endl;
					}
					int purchaseChoice = 0;
					cout << "請問要購買哪項 ? (0:離開)";
					cin >> purchaseChoice;
					if (purchaseChoice == 0)
						break;
					while (purchaseChoice < 0 || purchaseChoice > map.foodId.size()) {
						cout << "無此選項!!請重新選擇：";
						cin >> purchaseChoice;
					}
					string itemName = map.foodName[purchaseChoice - 1];
					vector<string>::iterator it = find(map.foodName.begin(), map.foodName.end(), itemName);
					if (it != map.foodName.end()) {
						int itemPosition = distance(map.foodName.begin(), it);
						if (itemPosition >= 0 && itemPosition < 5) {
							//cout << "防具" << endl;
							int purchaseConfirm = 0;
							if (chtr.coin > map.foodPlus[itemPosition]) {
								cout << "確認購買嗎? 1: 是 / 2: 否";
								cin >> purchaseConfirm;
								if (purchaseConfirm == 1) {
									chtr.bag.push_back(map.foodName[itemPosition]);
								}
								else {
									break;
								}
							}
							else {
								cout << "你擁有的金幣不足，請再接再厲。" << endl;
								break;
							}
							int equipConfirm = 0;
							cout << "請問要馬上使用嗎? 1:是 / 2:否" << endl;
							cout << "使用前生命值 : " << chtr.hp << endl;
							cout << "使用後生命值 : " << chtr.hp + map.foodPlus[itemPosition] << endl;
							cin >> equipConfirm;
							if (equipConfirm == 1) {
								if (chtr.mp == chtr.maxMp) {
									cout << "魔力值已滿!無須補魔!" << endl;
									break;
								}
								else if (chtr.mp + allItemList[itemPosition].itemPlus > chtr.maxMp) {
									chtr.mp = chtr.maxMp;
									chtr.bag.erase(chtr.bag.begin() + chtr.bag.size());
								}
								else {
									chtr.mp += allItemList[itemPosition].itemPlus;
									chtr.bag.erase(chtr.bag.begin() + chtr.bag.size());
								}
							}
						}
					}
					break;
				}
				case 4: {
					cout << "物品列表 : " << endl;
					for (int i = 0; i < map.poisonName.size(); i++) {
						cout << i + 1 << "." << map.poisonName[i] << "\t\t價格 : " << map.poisonPlus[i];
						cout << endl;
					}
					int purchaseChoice = 0;
					cout << "請問要購買哪項 ? (0:離開)";
					cin >> purchaseChoice;
					if (purchaseChoice == 0)
						break;
					while (purchaseChoice < 0 || purchaseChoice > map.poisonId.size()) {
						cout << "無此選項!!請重新選擇：";
						cin >> purchaseChoice;
					}
					string itemName = map.poisonName[purchaseChoice - 1];
					vector<string>::iterator it = find(map.poisonName.begin(), map.poisonName.end(), itemName);
					if (it != map.poisonName.end()) {
						int itemPosition = distance(map.poisonName.begin(), it);
						if (itemPosition >= 0 && itemPosition < 5) {
							//cout << "防具" << endl;
							int purchaseConfirm = 0;
							if (chtr.coin > map.poisonPlus[itemPosition]) {
								cout << "確認購買嗎? 1: 是 / 2: 否";
								cin >> purchaseConfirm;
								if (purchaseConfirm == 1) {
									chtr.bag.push_back(map.poisonName[itemPosition]);
								}
								else {
									break;
								}
							}
							else {
								cout << "你擁有的金幣不足，請再接再厲。" << endl;
								break;
							}
							int equipConfirm = 0;
							cout << "請問要馬上使用嗎? 1:是 / 2:否" << endl;
							cout << "使用前魔力值 : " << chtr.mp << endl;
							cout << "使用後魔力值 : " << chtr.mp + map.poisonPlus[itemPosition] << endl;
							cin >> equipConfirm;
							if (equipConfirm == 1) {
								if (chtr.mp == chtr.maxMp) {
									cout << "魔力值已滿!無須補魔!" << endl;
									break;
								}
								else if (chtr.mp + allItemList[itemPosition].itemPlus > chtr.maxMp)
									chtr.mp = chtr.maxMp;
								else
									chtr.mp += allItemList[itemPosition].itemPlus;
							}
						}
					}
					break;
				}
				case 5:
					cout << "1:是的，補滿。 / 2:不用了，謝謝。" << endl;
					int buwang = 0;
					cin >> buwang;
					if (buwang == 1) {
						chtr.hp = chtr.maxHp;
						chtr.mp = chtr.maxMp;
						cout << "已幫你補滿囉！" << endl;
						cout << "當前屬性數值如下：" << endl <<
							"當前生命值 / 最大生命值" << chtr.hp << "/" << chtr.maxHp << endl <<
							"當前魔力值 / 最大魔力值" << chtr.mp << "/" << chtr.maxMp << endl <<
							"當前攻擊力" << chtr.atk << endl;
					}
					break;
				}

			}
			break;
		}
		case 'b':
			if (chtr.bag.size() <= 0)
				cout << "你的背包空空如也......" << endl;
			else {
				int choiceItem;
				for (int i = 0; i < chtr.bag.size(); i++)
					cout << i + 1 << " ." << chtr.bag[i] << endl;
				cout << "目前持有金幣 : " << chtr.coin << endl;
				cout << "請問要使用幾號道具/穿戴幾號裝備 ? (0:離開)";
				cin >> choiceItem;
				if (choiceItem == 0)
					break;
				item bagItem;
				bagItem.itemName = chtr.bag[choiceItem - 1];
				vector<item>::iterator it = find(allItemList.begin(), allItemList.end(), bagItem);
				if (it != allItemList.end()) {
					int itemPosition = distance(allItemList.begin(), it);
					if (itemPosition >= 0 && itemPosition < 5) {
						//cout << "武器" << endl;
						if (chtr.atk > 100) {
							int equipChange = 0;
							cout << "你目前已裝備武器，使否先脫下裝備? 1:是 / 2:否";
							cin >> equipChange;
							if (equipChange == 1) {
								item lpItem;
								lpItem.itemPlus = chtr.atk - 100;
								vector<item>::iterator lp = find(allItemList.begin(), allItemList.begin() + 4, lpItem);
								int lpItemPosition = distance(allItemList.begin(), lp);
								chtr.atk = 100;
								chtr.bag.push_back(allItemList[lpItemPosition].itemName);
							}
						}
						cout << "裝備前攻擊力 : " << chtr.atk << endl;
						cout << "裝備後攻擊力 : " << chtr.atk + allItemList[itemPosition].itemPlus << endl;
						cout << "確認是否裝備? 1:是 / 2:否" << endl;
						int equip;
						cin >> equip;
						if (equip == 1) {
							chtr.atk += allItemList[itemPosition].itemPlus;
							chtr.bag.erase(chtr.bag.begin() + choiceItem - 1);
						}
					}
					else if (itemPosition >= 5 && itemPosition < 10) {
						//cout << "防具" << endl;
						if (chtr.maxHp > 100) {
							int equipChange = 0;
							cout << "你目前已裝備防具，使否先脫下裝備? 1:是 / 2:否";
							cin >> equipChange;
							if (equipChange == 1) {
								item lpItem;
								lpItem.itemPlus = chtr.maxHp - 100;
								vector<item>::iterator lp = find(allItemList.begin() + 5, allItemList.begin() + 9, lpItem);
								int lpItemPosition = distance(allItemList.begin(), lp);
								chtr.maxHp = 100;
								chtr.bag.push_back(allItemList[lpItemPosition].itemName);
							}
						}
						cout << "裝備前最大生命力 : " << chtr.maxHp << endl;
						cout << "裝備後最大生命力 : " << chtr.maxHp + allItemList[itemPosition].itemPlus << endl;
						cout << "確認是否裝備? 1:是 / 2:否" << endl;
						int equip;
						cin >> equip;
						if (equip == 1) {
							chtr.maxHp += allItemList[itemPosition].itemPlus;
							chtr.bag.erase(chtr.bag.begin() + choiceItem - 1);
						}
					}
					else if (itemPosition >= 10 && itemPosition < 15) {
						//cout << "藥水" << endl;
						cout << "使用前魔力 : " << chtr.mp << endl;
						cout << "使用後魔力 : " << (chtr.mp + allItemList[itemPosition].itemPlus > chtr.maxMp ? chtr.maxMp : chtr.mp) << endl;
						cout << "確認是否使用? 1:是 / 2:否" << endl;
						int equip;
						cin >> equip;
						if (equip == 1) {
							if (chtr.mp == chtr.maxMp) {
								cout << "魔力值已滿!無須補魔!" << endl;
								break;
							}
							else if (chtr.mp + allItemList[itemPosition].itemPlus > chtr.maxMp) {
								chtr.mp = chtr.maxMp;
								chtr.bag.erase(chtr.bag.begin() + choiceItem - 1);
							}
							else {
								chtr.mp += allItemList[itemPosition].itemPlus;
								chtr.bag.erase(chtr.bag.begin() + choiceItem - 1);
							}
						}
					}
					else if (itemPosition >= 15 && itemPosition < 20) {
						//cout << "食物" << endl;
						cout << "使用前生命力 : " << chtr.hp << endl;
						cout << "使用後生命力 : " << (chtr.hp + allItemList[itemPosition].itemPlus > chtr.maxHp ? chtr.maxHp : chtr.hp) << endl;
						cout << "確認是否使用? 1:是 / 2:否" << endl;
						int equip;
						cin >> equip;
						if (equip == 1) {
							if (chtr.hp == chtr.maxHp) {
								cout << "生命值已滿!無須補血!" << endl;
								break;
							}
							else if (chtr.hp + allItemList[itemPosition].itemPlus > chtr.maxHp) {
								chtr.hp = chtr.maxHp;
								chtr.bag.erase(chtr.bag.begin() + choiceItem - 1);
							}
							else {
								chtr.hp += allItemList[itemPosition].itemPlus;
								chtr.bag.erase(chtr.bag.begin() + choiceItem - 1);
							}
						}
					}
				}
				//chtr.bag.erase(chtr.bag.begin() + choiceItem - 1);
			}
			break;
		case 'c': {
			cout << "當前等級：" << chtr.level << endl;
			cout << "目前經驗值%數 : " << chtr.exp * 100 / chtr.levelExp << " %" << endl;
			cout << "當前生命力/最大生命力 : " << chtr.hp << "/" << chtr.maxHp << endl;
			cout << "當前魔力/最大魔力 : " << chtr.mp << "/" << chtr.maxMp << endl;
			cout << "當前攻擊力 : " << chtr.atk << endl;
			break;
		}
		case 'k': {
			cout << endl << "進入對戰中." << endl;
			Sleep(500);
			system("cls");
			cout << endl << "進入對戰中.." << endl;
			Sleep(500);
			system("cls");
			cout << endl << "進入對戰中..." << endl;
			Sleep(500);
			system("cls");
			cout << endl << "載入完成!" << endl;
			Sleep(1000);
			system("cls");

			fightscene = 1;

			int chooseAorS = 0;
			cout << "請選擇要使用技能或普通攻擊 (1:普通攻擊 / 2:技能攻擊) : ";
			cin >> chooseAorS;

			while (chtr.hp != 0 && mstTotalList[currentMonsterVectorPositionBuffer].hp != 0) {
				if (chooseAorS == 1) {
					mstTotalList[currentMonsterVectorPositionBuffer].hp -= chtr.atk;
					chtr.hp -= mstTotalList[currentMonsterVectorPositionBuffer].atk;

					cout << "你隨便一揮，造成怪物 " << chtr.atk << "點 傷害" << endl;
					cout << "怪物神經病亂吼，對你造成 " << mstTotalList[currentMonsterVectorPositionBuffer].atk << "點 傷害" << endl;

					Sleep(1000);

					cout << "角色血量 : ";
					float chtrhpslotlen = (float)chtr.maxHp / MAXBARLEN;
					int chtrhp = (int)ceil(chtr.hp / chtrhpslotlen);
					for (int i = 0; i < chtrhp; i++) {
						cout << "@";
					}
					chtrhp = (int)floor((chtr.maxHp - chtr.hp) / chtrhpslotlen);
					for (int i = 0; i < chtrhp; i++) {
						cout << " ";
					}
					cout << "|";
					cout << "角色魔力 : ";
					float chtrmpslotlen = (float)chtr.maxMp / MAXBARLEN;
					int chtrmp = (int)ceil(chtr.mp / chtrmpslotlen);
					for (int i = 0; i < chtrmp; i++) {
						cout << "$";
					}
					cout << endl;
					cout << "怪物血量 : ";
					float msthpslotlen = (float)mstTotalList[currentMonsterVectorPositionBuffer].maxHp / MAXBARLEN;
					int msthp = (int)ceil(mstTotalList[currentMonsterVectorPositionBuffer].hp / msthpslotlen);
					for (int i = 0; i < msthp; i++) {
						cout << "#";
					}
					msthp = (int)floor((mstTotalList[currentMonsterVectorPositionBuffer].maxHp - mstTotalList[currentMonsterVectorPositionBuffer].hp) / msthpslotlen);
					for (int i = 0; i < msthp; i++) {
						cout << " ";
					}
					cout << endl << endl;

					if (chtr.hp <= 0) {
						chtr.hp = 0;
						break;
					}
					if (mstTotalList[currentMonsterVectorPositionBuffer].hp <= 0) {
						mstTotalList[currentMonsterVectorPositionBuffer].hp = 0;
						break;
					}
				}
				else if (chooseAorS == 2) {

					for (int i = 0; i <= log2_log(chtr.level); i++) {
						cout << i + 1 << ". " << map.skillName[i] << " 等級: " << chtrSkillList[i].skillLevel << " ( 熟練度 " << chtrSkillList[i].skillExp << " / 10 )" << endl;
					}
					cout << "尚未習得技能 : " << endl;
					for (int i = log2_log(chtr.level * 2); i < map.skillName.size(); i++) {
						cout << "等級 : " << pow(2, i) << " 可學習 " << map.skillName[i] << " 技能。" << endl;
					}

					int skillChoice = 0;
					cout << "請選擇想使用之技能 : ";
					cin >> skillChoice;
					while (skillChoice - 1 > log2_log(chtr.level)) {
						cout << "無此技能可用!!請重新選擇!!" << endl;
						system("pause");
						cout << "請選擇想使用之技能 : ";
						cin >> skillChoice;
					}
					switch (skillChoice) {
					case 1: {
						if (chtr.mp < chtrSkillList[0].skillCost) {
							cout << "魔力不足喔喔喔喔喔!!無法使用~~" << endl;
							system("pause");
							break;
						}

						mstTotalList[currentMonsterVectorPositionBuffer].hp -= chtrSkillList[0].skillPlus;
						chtr.mp -= chtrSkillList[0].skillCost;
						chtr.hp -= mstTotalList[currentMonsterVectorPositionBuffer].atk;
						chtrSkillList[0].skillExp++;
						cout << "對著怪物 " << map.skillName[0] << " , 對其造成 " << chtrSkillList[0].skillPlus << "點 傷害, 獲得 1 點熟練度" << endl;

						if (chtrSkillList[0].skillExp % 10 == 0) {
							chtrSkillList[0].skillLevel++;
							chtrSkillList[0].skillExp = 0;
							cout << endl;
							cout << "恭喜技能升等囉!!增加 " << chtrSkillList[0].skillPlus / 2 << " 傷害" << endl;
							chtrSkillList[0].skillPlus = chtrSkillList[0].skillPlus + chtrSkillList[0].skillPlus / 2;
						}
						cout << endl;
						cout << "怪物神經病亂吼，對你造成 " << mstTotalList[currentMonsterVectorPositionBuffer].atk << "點 傷害" << endl;
						Sleep(1000);

						cout << "角色血量 : ";
						float chtrhpslotlen = (float)chtr.maxHp / MAXBARLEN;
						int chtrhp = (int)ceil(chtr.hp / chtrhpslotlen);
						for (int i = 0; i < chtrhp; i++) {
							cout << "@";
						}
						chtrhp = (int)floor((chtr.maxHp - chtr.hp) / chtrhpslotlen);
						for (int i = 0; i < chtrhp; i++) {
							cout << " ";
						}
						cout << "|";
						cout << "角色魔力 : ";
						float chtrmpslotlen = (float)chtr.maxMp / MAXBARLEN;
						int chtrmp = (int)ceil(chtr.mp / chtrmpslotlen);
						for (int i = 0; i < chtrmp; i++) {
							cout << "$";
						}

						cout << endl;

						cout << "怪物血量 : ";
						float msthpslotlen = (float)mstTotalList[currentMonsterVectorPositionBuffer].maxHp / MAXBARLEN;
						int msthp = (int)ceil(mstTotalList[currentMonsterVectorPositionBuffer].hp / msthpslotlen);
						for (int i = 0; i < msthp; i++) {
							cout << "#";
						}

						cout << endl << endl;
						break;
					}
					case 2: {
						if (chtr.mp < chtrSkillList[1].skillCost) {
							cout << "魔力不足喔喔喔喔喔!!無法使用~~" << endl;
							system("pause");
							break;
						}
						mstTotalList[currentMonsterVectorPositionBuffer].hp -= chtrSkillList[1].skillPlus;
						chtr.mp -= chtrSkillList[1].skillCost;
						chtr.hp -= mstTotalList[currentMonsterVectorPositionBuffer].atk;
						chtrSkillList[1].skillExp++;
						cout << "對著怪物 " << map.skillName[1] << " , 對其造成 " << map.skillPlus[1] << "點 傷害" << endl;
						if (chtrSkillList[1].skillExp % 10 == 0) {
							chtrSkillList[1].skillLevel++;
							chtrSkillList[1].skillExp = 0;
							chtrSkillList[1].skillPlus += chtrSkillList[1].skillPlus / 2;
							cout << "恭喜技能升等囉!!增加 " << chtrSkillList[1].skillPlus / 2 << " 傷害";
						}
						cout << "怪物神經病亂吼，對你造成 " << mstTotalList[currentMonsterVectorPositionBuffer].atk << "點 傷害" << endl;
						Sleep(1000);

						cout << "角色血量 : ";
						float chtrhpslotlen = (float)chtr.maxHp / MAXBARLEN;
						int chtrhp = (int)ceil(chtr.hp / chtrhpslotlen);
						for (int i = 0; i < chtrhp; i++) {
							cout << "@";
						}
						cout << "\t";
						cout << "角色魔力 : ";
						float chtrmpslotlen = (float)chtr.maxMp / MAXBARLEN;
						int chtrmp = (int)ceil(chtr.mp / chtrmpslotlen);
						for (int i = 0; i < chtrmp; i++) {
							cout << "$";
						}

						cout << endl;

						cout << "怪物血量 : ";
						float msthpslotlen = (float)mstTotalList[currentMonsterVectorPositionBuffer].maxHp / MAXBARLEN;
						int msthp = (int)ceil(mstTotalList[currentMonsterVectorPositionBuffer].hp / msthpslotlen);
						for (int i = 0; i < msthp; i++) {
							cout << "#";
						}

						cout << endl << endl;
						break;
					}
					case 3: {
						if (chtr.mp < chtrSkillList[2].skillCost) {
							cout << "魔力不足喔喔喔喔喔!!無法使用~~" << endl;
							system("pause");
							break;
						}
						mstTotalList[currentMonsterVectorPositionBuffer].hp -= chtrSkillList[2].skillPlus;
						chtr.mp -= chtrSkillList[2].skillCost;
						chtr.hp -= mstTotalList[currentMonsterVectorPositionBuffer].atk;
						chtrSkillList[2].skillExp++;
						cout << "對著怪物 " << map.skillName[2] << " , 對其造成 " << map.skillPlus[2] << "點 傷害" << endl;
						if (chtrSkillList[2].skillExp % 10 == 0) {
							chtrSkillList[2].skillLevel++;
							chtrSkillList[2].skillExp = 0;
							chtrSkillList[2].skillPlus += chtrSkillList[2].skillPlus / 2;
							cout << "恭喜技能升等囉!!增加 " << chtrSkillList[2].skillPlus / 2 << " 傷害";
						}
						cout << "怪物神經病亂吼，對你造成 " << mstTotalList[currentMonsterVectorPositionBuffer].atk << "點 傷害" << endl;
						Sleep(1000);

						cout << "角色血量 : ";
						float chtrhpslotlen = (float)chtr.maxHp / MAXBARLEN;
						int chtrhp = (int)ceil(chtr.hp / chtrhpslotlen);
						for (int i = 0; i < chtrhp; i++) {
							cout << "@";
						}
						cout << "\t";
						cout << "角色魔力 : ";
						float chtrmpslotlen = (float)chtr.maxMp / MAXBARLEN;
						int chtrmp = (int)ceil(chtr.mp / chtrmpslotlen);
						for (int i = 0; i < chtrmp; i++) {
							cout << "$";
						}

						cout << endl;

						cout << "怪物血量 : ";
						float msthpslotlen = (float)mstTotalList[currentMonsterVectorPositionBuffer].maxHp / MAXBARLEN;
						int msthp = (int)ceil(mstTotalList[currentMonsterVectorPositionBuffer].hp / msthpslotlen);
						for (int i = 0; i < msthp; i++) {
							cout << "#";
						}

						cout << endl << endl;
						break;
					}
					case 4: {
						if (chtr.mp < chtrSkillList[3].skillCost) {
							cout << "魔力不足喔喔喔喔喔!!無法使用~~" << endl;
							system("pause");
							break;
						}
						mstTotalList[currentMonsterVectorPositionBuffer].hp -= chtrSkillList[3].skillPlus;
						chtr.mp -= chtrSkillList[3].skillCost;
						chtr.hp -= mstTotalList[currentMonsterVectorPositionBuffer].atk;
						chtrSkillList[3].skillExp++;
						cout << "對著怪物 " << map.skillName[3] << " , 對其造成 " << map.skillPlus[3] << "點 傷害" << endl;
						if (chtrSkillList[3].skillExp % 10 == 0) {
							chtrSkillList[3].skillLevel++;
							chtrSkillList[3].skillExp = 0;
							chtrSkillList[3].skillPlus += chtrSkillList[3].skillPlus / 2;
							cout << "恭喜技能升等囉!!增加 " << chtrSkillList[3].skillPlus / 2 << " 傷害";
						}
						cout << "怪物神經病亂吼，對你造成 " << mstTotalList[currentMonsterVectorPositionBuffer].atk << "點 傷害" << endl;
						Sleep(1000);

						cout << "角色血量 : ";
						float chtrhpslotlen = (float)chtr.maxHp / MAXBARLEN;
						int chtrhp = (int)ceil(chtr.hp / chtrhpslotlen);
						for (int i = 0; i < chtrhp; i++) {
							cout << "@";
						}
						cout << "\t";
						cout << "角色魔力 : ";
						float chtrmpslotlen = (float)chtr.maxMp / MAXBARLEN;
						int chtrmp = (int)ceil(chtr.mp / chtrmpslotlen);
						for (int i = 0; i < chtrmp; i++) {
							cout << "$";
						}

						cout << endl;

						cout << "怪物血量 : ";
						float msthpslotlen = (float)mstTotalList[currentMonsterVectorPositionBuffer].maxHp / MAXBARLEN;
						int msthp = (int)ceil(mstTotalList[currentMonsterVectorPositionBuffer].hp / msthpslotlen);
						for (int i = 0; i < msthp; i++) {
							cout << "#";
						}

						cout << endl << endl;
						break;
					}
					case 5: {
						if (chtr.mp < chtrSkillList[4].skillCost) {
							cout << "魔力不足喔喔喔喔喔!!無法使用~~" << endl;
							system("pause");
							break;
						}
						mstTotalList[currentMonsterVectorPositionBuffer].hp -= chtrSkillList[4].skillPlus;
						chtr.mp -= chtrSkillList[4].skillCost;
						chtr.hp -= mstTotalList[currentMonsterVectorPositionBuffer].atk;
						chtrSkillList[4].skillExp++;
						cout << "對著怪物 " << map.skillName[4] << " , 對其造成 " << map.skillPlus[4] << "點 傷害" << endl;
						if (chtrSkillList[4].skillExp % 10 == 0) {
							chtrSkillList[4].skillLevel++;
							chtrSkillList[4].skillExp = 0;
							chtrSkillList[4].skillPlus += chtrSkillList[4].skillPlus / 2;
							cout << "恭喜技能升等囉!!增加 " << chtrSkillList[4].skillPlus / 2 << " 傷害";
						}
						cout << "怪物神經病亂吼，對你造成 " << mstTotalList[currentMonsterVectorPositionBuffer].atk << "點 傷害" << endl;
						Sleep(1000);

						cout << "角色血量 : ";
						float chtrhpslotlen = (float)chtr.maxHp / MAXBARLEN;
						int chtrhp = (int)ceil(chtr.hp / chtrhpslotlen);
						for (int i = 0; i < chtrhp; i++) {
							cout << "@";
						}
						cout << "\t";
						cout << "角色魔力 : ";
						float chtrmpslotlen = (float)chtr.maxMp / MAXBARLEN;
						int chtrmp = (int)ceil(chtr.mp / chtrmpslotlen);
						for (int i = 0; i < chtrmp; i++) {
							cout << "$";
						}

						cout << endl;

						cout << "怪物血量 : ";
						float msthpslotlen = (float)mstTotalList[currentMonsterVectorPositionBuffer].maxHp / MAXBARLEN;
						int msthp = (int)ceil(mstTotalList[currentMonsterVectorPositionBuffer].hp / msthpslotlen);
						for (int i = 0; i < msthp; i++) {
							cout << "#";
						}

						cout << endl << endl;
						break;
					}
					}

					if (chtr.hp <= 0) {
						chtr.hp = 0;
						break;
					}
					if (mstTotalList[currentMonsterVectorPositionBuffer].hp <= 0) {
						mstTotalList[currentMonsterVectorPositionBuffer].hp = 0;
						break;
					}
				}
				else {
					cout << "無此選項!!" << endl;
				}
				cout << "請選擇要使用技能或普通攻擊 (1:普通攻擊 / 2:技能攻擊) : ";
				cin >> chooseAorS;
			}
			if (chtr.hp <= 0) {
				cout << "戰鬥失敗...回到城鎮!!";
				worldMap.position = 3;
				map.chtr_location_x = 20;
				map.chtr_location_y = 10;
				chtr.hp = 100;
				system("pause");
				system("cls");
				currentMonsterVectorPosition = 0;
				currentMonsterVectorPositionBuffer = 0;
			}
			else if (mstTotalList[currentMonsterVectorPositionBuffer].hp <= 0) {
				randomItem = rand() % 20;
				randomExp = rand() % 50 + 10;
				randomCoin = rand() % 20 + 5;
				randomMstPdc(map);

				int choice = 0;
				cout << "戰鬥勝利!! 獲得經驗值 : " << randomExp << endl;
				chtr.exp += randomExp;
				if (chtr.exp > chtr.levelExp) {
					chtr.level++;
					chtr.levelExp += 50;
					chtr.exp = 0;
					cout << "恭喜你！升等囉！目前等級：" << chtr.level << endl;
				}
				cout << "掉落物品 : " << allItemList[randomItem].itemName << "/ 掉落金幣 : " << randomCoin << endl;
				cout << "請問是否撿取 ? (1:是/2:否)";
				cin >> choice;

				switch (choice) {
				case 1:
					chtr.bag.push_back(allItemList[randomItem].itemName);
					chtr.coin += randomCoin;
					break;
				case 2:
					break;
				}
				map.randnum_monster1 = rand() % 25;
				map.randnum_monster2 = rand() % 25;
				map.randnum_monster3 = rand() % 25;
				map.randnum_monster4 = rand() % 25;
				map.randnum_monster5 = rand() % 25;
				randomMstPdc(map);
				system("pause");
				system("cls");
				currentMonsterVectorPosition = 0;
				currentMonsterVectorPositionBuffer = 0;
			}
			fightscene = 0;
			break; }
		case'f': {
			ofstream filePtrNormal;
			ofstream filePtrBag;
			dataSaved outputData;

			outputData.savedBag = chtr.bag;
			outputData.chtrAtk = chtr.atk;
			outputData.chtrHp = chtr.maxHp;
			outputData.chtrMp = chtr.maxMp;
			outputData.chtrLvl = chtr.level;
			outputData.chtrCoin = chtr.coin;
			outputData.chtrExp = chtr.exp;
			outputData.chtrSkill1Lvl = chtrSkillList[0].skillLevel;
			outputData.chtrSkill1Exp = chtrSkillList[0].skillExp;
			outputData.chtrSkill2Lvl = chtrSkillList[1].skillLevel;
			outputData.chtrSkill2Exp = chtrSkillList[1].skillExp;
			outputData.chtrSkill3Lvl = chtrSkillList[2].skillLevel;
			outputData.chtrSkill3Exp = chtrSkillList[2].skillExp;
			outputData.chtrSkill4Lvl = chtrSkillList[3].skillLevel;
			outputData.chtrSkill4Exp = chtrSkillList[3].skillExp;
			outputData.chtrSkill5Lvl = chtrSkillList[4].skillLevel;
			outputData.chtrSkill5Exp = chtrSkillList[4].skillExp;


			filePtrBag.open("C:\\gameDataFolder\\bag.txt", ios::out);
			for (int i = 0; i < chtr.bag.size(); i++)
				filePtrBag << outputData.savedBag[i] << endl;


			filePtrNormal.open("C:\\gameDataFolder\\player.txt", ios::out);
			filePtrNormal << outputData.chtrLvl << "\n";
			filePtrNormal << outputData.chtrHp << "\n";
			filePtrNormal << outputData.chtrMp << "\n";
			filePtrNormal << outputData.chtrAtk << "\n";
			filePtrNormal << outputData.chtrCoin << "\n";
			filePtrNormal << outputData.chtrExp << "\n";

			filePtrNormal << outputData.chtrSkill1Lvl << "\n";
			filePtrNormal << outputData.chtrSkill1Exp << "\n";
			filePtrNormal << outputData.chtrSkill2Lvl << "\n";
			filePtrNormal << outputData.chtrSkill2Exp << "\n";
			filePtrNormal << outputData.chtrSkill3Lvl << "\n";
			filePtrNormal << outputData.chtrSkill3Exp << "\n";
			filePtrNormal << outputData.chtrSkill4Lvl << "\n";
			filePtrNormal << outputData.chtrSkill4Exp << "\n";
			filePtrNormal << outputData.chtrSkill5Lvl << "\n";
			filePtrNormal << outputData.chtrSkill5Exp << "\n";

			filePtrBag.close();
			filePtrNormal.close();

			exit(0);
		}
		default: {
			cout << "無此指令!!" << endl;
			break;
		}
		}//end of switchCase
		if ((worldMap.position - 1) == 2) {
			map.town_initialize();
		}
		else {
			if (fightscene == 0) {
				mstTotalList = map.normal_initialize(mstWeakList, mstMiddleList, mstHardList);
				if ((map.chtr_location_x == map.randnum_monster2 / 5 * 8 + 4 && map.chtr_location_y == map.randnum_monster1 / 5 * 4 + 2) ||
					(map.chtr_location_x == map.randnum_monster3 / 5 * 8 + 4 && map.chtr_location_y == map.randnum_monster2 / 5 * 4 + 2) ||
					(map.chtr_location_x == map.randnum_monster4 / 5 * 8 + 4 && map.chtr_location_y == map.randnum_monster3 / 5 * 4 + 2) ||
					(map.chtr_location_x == map.randnum_monster5 / 5 * 8 + 4 && map.chtr_location_y == map.randnum_monster4 / 5 * 4 + 2) ||
					(map.chtr_location_x == map.randnum_monster1 / 5 * 8 + 4 && map.chtr_location_y == map.randnum_monster5 / 5 * 4 + 2)
					) {
					cout << "遭遇怪物！是否進入戰鬥?" << endl;
					currentMosterX = map.chtr_location_x;
					currentMosterY = map.chtr_location_y;

					int monsterX = (map.chtr_location_x - 4) / 8;
					int monsterY = (map.chtr_location_y - 2) / 4;
					int searchX = 0;

					vector<int>::iterator itX = find(map.monster_x.begin(), map.monster_x.end(), monsterX);
					vector<int>::iterator itY = find(map.monster_y.begin(), map.monster_y.end(), monsterY);

					if (itX != map.monster_x.end() && itY != map.monster_y.end()) {

						int monsterVectorPositionX = distance(map.monster_x.begin(), itX);
						int monsterVectorPositionY = distance(map.monster_y.begin(), itY);

						while (monsterVectorPositionX != monsterVectorPositionY) {

							if (monsterVectorPositionX > monsterVectorPositionY) {
								itY = find(map.monster_y.begin() + ((monsterVectorPositionY == 0) ? 1 : monsterVectorPositionY + 1), map.monster_y.end(), monsterY);
								monsterVectorPositionY = distance(map.monster_y.begin(), itY);
							}
							else {
								itX = find(map.monster_x.begin() + ((monsterVectorPositionX == 0) ? 1 : monsterVectorPositionX + 1), map.monster_x.end(), monsterX);
								monsterVectorPositionX = distance(map.monster_x.begin(), itX);
							}
							if (monsterVectorPositionX == monsterVectorPositionY)break;
						}
						currentMonsterVectorPosition = monsterVectorPositionX;
						currentMonsterVectorPositionBuffer = monsterVectorPositionX;
						cout << "你選擇對戰的是 : " << monsterVectorPositionX + 1 << ". " << mstTotalList[monsterVectorPositionX].name << endl;
					}

				}

			}
			else {
				system("cls");
			}
		}

		cout << "請輸入指令(w:上/s:下/a:左/d:右/e:互動/k:打架/c:人物狀態/m:世界地圖/b:打開背包/f:離開):";
		cin >> chtr.movement;

	}// end of move while

	cout << "Exit!!!" << endl;
	system("pause");
	finPlayer.close();
	finMap.close();
	//ffout.close();
	return 0;
}




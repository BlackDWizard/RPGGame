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
		cout << "W:�Z����, A:���㩱, F:�����u, P:�Ĥ��Q, B:���ɯ�" << endl << endl;

		if (chtr_location_x == 4 && chtr_location_y == 2) {
			cout << "�Z�����A�аݬO�_�J�����ʡH" << endl;
			item_menu = 1;
		}
		else if (chtr_location_x == 12 && chtr_location_y == 10) {
			cout << "�Y�����㩱�A�аݬO�_�J�����ʡH" << endl;
			item_menu = 2;
		}
		else if (chtr_location_x == 28 && chtr_location_y == 14) {
			cout << "�����u�A�аݬO�_�J�����ʡH" << endl;
			item_menu = 3;
		}
		else if (chtr_location_x == 28 && chtr_location_y == 6) {
			cout << "�Ĥ��Q�A�аݬO�_�J�����ʡH" << endl;
			item_menu = 4;
		}
		else if (chtr_location_x == 12 && chtr_location_y == 18) {
			cout << "���ɯ��A�аݬO�_�ɺ�HP/MP�H" << endl;
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
		cout << "�i�̷�e��m:(" << (chtr_location_x - 4) / 8 << "," << (chtr_location_y - 2) / 4 << ")" << endl;
		cout << "��e�s�b�Ǫ� : " << endl;
		for (int i = 0; i < totalMst.size(); i++) {
			cout << i + 1 << ". " << totalMst[i].name << " ���� : " << totalMst[i].strength <<
				" ��q :" << totalMst[i].hp << " �����O :" << totalMst[i].atk
				<< " ��m�G(" << totalMstPositionX[i] << "," << totalMstPositionY[i] << ")" << endl;
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
		mapBuffer.randomVector.push_back(mapBuffer.randnum_monster1);   //�üƲ��͡A�üƲ��ͪ��d��O1~9
		mapBuffer.randomVector.push_back(mapBuffer.randnum_monster2);   //�üƲ��͡A�üƲ��ͪ��d��O1~9
		mapBuffer.randomVector.push_back(mapBuffer.randnum_monster3);   //�üƲ��͡A�üƲ��ͪ��d��O1~9
		mapBuffer.randomVector.push_back(mapBuffer.randnum_monster4);   //�üƲ��͡A�üƲ��ͪ��d��O1~9
		mapBuffer.randomVector.push_back(mapBuffer.randnum_monster5);   //�üƲ��͡A�üƲ��ͪ��d��O1~9

		for (int j = 0; j < i; j++)
		{
			while (mapBuffer.randomVector[j] == mapBuffer.randomVector[i])    //�ˬd�O�_�P�e�����ͪ��ƭȵo�ͭ��ơA�p�G���N���s����
			{
				j = 0;  //�p�����ơA�N�ܼ�j�]��0�A�A���ˬd (�]���٬O�����ƪ��i��)
				mapBuffer.randomVector[i] = rand() % 25;   //���s���͡A�s�^�}�C�A�üƲ��ͪ��d��O1~9
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

	cout << "�п�ܵn�J(sign)�����}(exit) : ";
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
			cout << "�п�ܵn�J(sign)�����}(exit) : ";
			cin >> command;
		}
	}
	HANDLE hFind;
	WIN32_FIND_DATA FindFileData;
	charactor chtr;
	vector<skill>chtrSkillList;//�[�J

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
			cout << "�s�C��!" << endl;
		}
		else
		{
			cout << "�аݭn�~��C����? ( 1:�O/2:�_ )" << endl;
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
	cout << "�п�J���O(w:�W/s:�U/a:��/d:�k/e:����/k:���[/c:�H�����A/m:�@�ɦa��/b:���}�I�]/f:���}):";
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
					cout << "�W�X�a����ɽЩ��^����" << endl;
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
					cout << "�W�X�a����ɽЩ��^����" << endl;
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
					cout << "�W�X�a����ɽЩ��^����" << endl;
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
					cout << "�W�X�a����ɽЩ��^����" << endl;
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
			cout << "��e�Ҧb��m : " << worldMap.regionName[worldMap.position - 1];
			cout << "��e�Ҧb��m : " << worldMap.regionId[worldMap.position - 1];
			cout << endl << endl;
			break;

		case 'e': {
			if ((worldMap.position - 1) == 2) {
				switch (map.item_menu) {
				case 1: {
					cout << "���~�C�� : " << endl;
					for (int i = 0; i < map.weaponName.size(); i++) {
						cout << i + 1 << "." << map.weaponName[i] << "\t\t���� : " << map.weaponPlus[i];
						cout << endl;
					}
					int purchaseChoice = 0;
					cout << "�аݭn�ʶR���� ? (0:���})";
					cin >> purchaseChoice;
					if (purchaseChoice == 0)
						break;
					while (purchaseChoice <= 0 || purchaseChoice > map.weaponId.size()) {
						cout << "�L���ﶵ!!�Э��s��ܡG";
						cin >> purchaseChoice;
					}
					string itemName = map.weaponName[purchaseChoice - 1];
					vector<string>::iterator it = find(map.weaponName.begin(), map.weaponName.end(), itemName);
					if (it != map.weaponName.end()) {
						int itemPosition = distance(map.weaponName.begin(), it);
						if (itemPosition >= 0 && itemPosition < 5) {
							//cout << "�Z��" << endl;
							int purchaseConfirm = 0;
							if (chtr.coin > map.weaponPlus[itemPosition]) {
								cout << "�T�{�ʶR��? 1: �O / 2: �_" << endl;
								cin >> purchaseConfirm;
								if (purchaseConfirm == 1) {
									chtr.bag.push_back(map.weaponName[itemPosition]);
								}
								else {
									break;
								}
							}
							else {
								cout << "�A�֦������������A�ЦA���A�F�C" << endl;
								break;
							}
							int equipConfirm = 0;
							cout << "�аݭn���W�˳ƶ�? 1:�O / 2:�_" << endl;
							cout << "�˳ƫe�����O : " << chtr.atk << endl;
							cout << "�˳ƫ�����O : " << chtr.atk + map.weaponPlus[itemPosition] << endl;
							cin >> equipConfirm;
							if (equipConfirm == 1) {
								chtr.atk += map.weaponPlus[itemPosition];
							}
						}
					}
					break;
				}
				case 2: {
					cout << "���~�C�� : " << endl;
					for (int i = 0; i < map.armorName.size(); i++) {
						cout << i + 1 << "." << map.armorName[i] << "\t\t���� : " << map.armorPlus[i];
						cout << endl;
					}
					int purchaseChoice = 0;
					cout << "�аݭn�ʶR���� ? (0:���})";
					cin >> purchaseChoice;
					if (purchaseChoice == 0)
						break;
					while (purchaseChoice < 0 || purchaseChoice > map.armorId.size()) {
						cout << "�L���ﶵ!!�Э��s��ܡG";
						cin >> purchaseChoice;
					}
					string itemName = map.armorName[purchaseChoice - 1];
					vector<string>::iterator it = find(map.armorName.begin(), map.armorName.end(), itemName);
					if (it != map.armorName.end()) {
						int itemPosition = distance(map.armorName.begin(), it);
						if (itemPosition >= 0 && itemPosition < 5) {
							//cout << "����" << endl;
							int purchaseConfirm = 0;
							if (chtr.coin > map.armorPlus[itemPosition]) {
								cout << "�T�{�ʶR��? 1: �O / 2: �_";
								cin >> purchaseConfirm;
								if (purchaseConfirm == 1) {
									chtr.bag.push_back(map.armorName[itemPosition]);
								}
								else {
									break;
								}
							}
							else {
								cout << "�A�֦������������A�ЦA���A�F�C" << endl;
								break;
							}
							int equipConfirm = 0;
							cout << "�аݭn���W�˳ƶ�? 1:�O / 2:�_" << endl;
							cout << "�˳ƫe�̤j�ͩR�� : " << chtr.maxHp << endl;
							cout << "�˳ƫ�̤j�ͩR�� : " << chtr.maxHp + map.armorPlus[itemPosition] << endl;
							cin >> equipConfirm;
							if (equipConfirm == 1) {
								chtr.maxHp += map.armorPlus[itemPosition];
							}
						}
					}
					break;
				}
				case 3: {
					cout << "���~�C�� : " << endl;
					for (int i = 0; i < map.foodName.size(); i++) {
						cout << i + 1 << "." << map.foodName[i] << "\t\t���� : " << map.foodPlus[i];
						cout << endl;
					}
					int purchaseChoice = 0;
					cout << "�аݭn�ʶR���� ? (0:���})";
					cin >> purchaseChoice;
					if (purchaseChoice == 0)
						break;
					while (purchaseChoice < 0 || purchaseChoice > map.foodId.size()) {
						cout << "�L���ﶵ!!�Э��s��ܡG";
						cin >> purchaseChoice;
					}
					string itemName = map.foodName[purchaseChoice - 1];
					vector<string>::iterator it = find(map.foodName.begin(), map.foodName.end(), itemName);
					if (it != map.foodName.end()) {
						int itemPosition = distance(map.foodName.begin(), it);
						if (itemPosition >= 0 && itemPosition < 5) {
							//cout << "����" << endl;
							int purchaseConfirm = 0;
							if (chtr.coin > map.foodPlus[itemPosition]) {
								cout << "�T�{�ʶR��? 1: �O / 2: �_";
								cin >> purchaseConfirm;
								if (purchaseConfirm == 1) {
									chtr.bag.push_back(map.foodName[itemPosition]);
								}
								else {
									break;
								}
							}
							else {
								cout << "�A�֦������������A�ЦA���A�F�C" << endl;
								break;
							}
							int equipConfirm = 0;
							cout << "�аݭn���W�ϥζ�? 1:�O / 2:�_" << endl;
							cout << "�ϥΫe�ͩR�� : " << chtr.hp << endl;
							cout << "�ϥΫ�ͩR�� : " << chtr.hp + map.foodPlus[itemPosition] << endl;
							cin >> equipConfirm;
							if (equipConfirm == 1) {
								if (chtr.mp == chtr.maxMp) {
									cout << "�]�O�Ȥw��!�L�����]!" << endl;
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
					cout << "���~�C�� : " << endl;
					for (int i = 0; i < map.poisonName.size(); i++) {
						cout << i + 1 << "." << map.poisonName[i] << "\t\t���� : " << map.poisonPlus[i];
						cout << endl;
					}
					int purchaseChoice = 0;
					cout << "�аݭn�ʶR���� ? (0:���})";
					cin >> purchaseChoice;
					if (purchaseChoice == 0)
						break;
					while (purchaseChoice < 0 || purchaseChoice > map.poisonId.size()) {
						cout << "�L���ﶵ!!�Э��s��ܡG";
						cin >> purchaseChoice;
					}
					string itemName = map.poisonName[purchaseChoice - 1];
					vector<string>::iterator it = find(map.poisonName.begin(), map.poisonName.end(), itemName);
					if (it != map.poisonName.end()) {
						int itemPosition = distance(map.poisonName.begin(), it);
						if (itemPosition >= 0 && itemPosition < 5) {
							//cout << "����" << endl;
							int purchaseConfirm = 0;
							if (chtr.coin > map.poisonPlus[itemPosition]) {
								cout << "�T�{�ʶR��? 1: �O / 2: �_";
								cin >> purchaseConfirm;
								if (purchaseConfirm == 1) {
									chtr.bag.push_back(map.poisonName[itemPosition]);
								}
								else {
									break;
								}
							}
							else {
								cout << "�A�֦������������A�ЦA���A�F�C" << endl;
								break;
							}
							int equipConfirm = 0;
							cout << "�аݭn���W�ϥζ�? 1:�O / 2:�_" << endl;
							cout << "�ϥΫe�]�O�� : " << chtr.mp << endl;
							cout << "�ϥΫ��]�O�� : " << chtr.mp + map.poisonPlus[itemPosition] << endl;
							cin >> equipConfirm;
							if (equipConfirm == 1) {
								if (chtr.mp == chtr.maxMp) {
									cout << "�]�O�Ȥw��!�L�����]!" << endl;
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
					cout << "1:�O���A�ɺ��C / 2:���ΤF�A���¡C" << endl;
					int buwang = 0;
					cin >> buwang;
					if (buwang == 1) {
						chtr.hp = chtr.maxHp;
						chtr.mp = chtr.maxMp;
						cout << "�w���A�ɺ��o�I" << endl;
						cout << "��e�ݩʼƭȦp�U�G" << endl <<
							"��e�ͩR�� / �̤j�ͩR��" << chtr.hp << "/" << chtr.maxHp << endl <<
							"��e�]�O�� / �̤j�]�O��" << chtr.mp << "/" << chtr.maxMp << endl <<
							"��e�����O" << chtr.atk << endl;
					}
					break;
				}

			}
			break;
		}
		case 'b':
			if (chtr.bag.size() <= 0)
				cout << "�A���I�]�ŪŦp�]......" << endl;
			else {
				int choiceItem;
				for (int i = 0; i < chtr.bag.size(); i++)
					cout << i + 1 << " ." << chtr.bag[i] << endl;
				cout << "�ثe�������� : " << chtr.coin << endl;
				cout << "�аݭn�ϥδX���D��/�����X���˳� ? (0:���})";
				cin >> choiceItem;
				if (choiceItem == 0)
					break;
				item bagItem;
				bagItem.itemName = chtr.bag[choiceItem - 1];
				vector<item>::iterator it = find(allItemList.begin(), allItemList.end(), bagItem);
				if (it != allItemList.end()) {
					int itemPosition = distance(allItemList.begin(), it);
					if (itemPosition >= 0 && itemPosition < 5) {
						//cout << "�Z��" << endl;
						if (chtr.atk > 100) {
							int equipChange = 0;
							cout << "�A�ثe�w�˳ƪZ���A�ϧ_����U�˳�? 1:�O / 2:�_";
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
						cout << "�˳ƫe�����O : " << chtr.atk << endl;
						cout << "�˳ƫ�����O : " << chtr.atk + allItemList[itemPosition].itemPlus << endl;
						cout << "�T�{�O�_�˳�? 1:�O / 2:�_" << endl;
						int equip;
						cin >> equip;
						if (equip == 1) {
							chtr.atk += allItemList[itemPosition].itemPlus;
							chtr.bag.erase(chtr.bag.begin() + choiceItem - 1);
						}
					}
					else if (itemPosition >= 5 && itemPosition < 10) {
						//cout << "����" << endl;
						if (chtr.maxHp > 100) {
							int equipChange = 0;
							cout << "�A�ثe�w�˳ƨ���A�ϧ_����U�˳�? 1:�O / 2:�_";
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
						cout << "�˳ƫe�̤j�ͩR�O : " << chtr.maxHp << endl;
						cout << "�˳ƫ�̤j�ͩR�O : " << chtr.maxHp + allItemList[itemPosition].itemPlus << endl;
						cout << "�T�{�O�_�˳�? 1:�O / 2:�_" << endl;
						int equip;
						cin >> equip;
						if (equip == 1) {
							chtr.maxHp += allItemList[itemPosition].itemPlus;
							chtr.bag.erase(chtr.bag.begin() + choiceItem - 1);
						}
					}
					else if (itemPosition >= 10 && itemPosition < 15) {
						//cout << "�Ĥ�" << endl;
						cout << "�ϥΫe�]�O : " << chtr.mp << endl;
						cout << "�ϥΫ��]�O : " << (chtr.mp + allItemList[itemPosition].itemPlus > chtr.maxMp ? chtr.maxMp : chtr.mp) << endl;
						cout << "�T�{�O�_�ϥ�? 1:�O / 2:�_" << endl;
						int equip;
						cin >> equip;
						if (equip == 1) {
							if (chtr.mp == chtr.maxMp) {
								cout << "�]�O�Ȥw��!�L�����]!" << endl;
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
						//cout << "����" << endl;
						cout << "�ϥΫe�ͩR�O : " << chtr.hp << endl;
						cout << "�ϥΫ�ͩR�O : " << (chtr.hp + allItemList[itemPosition].itemPlus > chtr.maxHp ? chtr.maxHp : chtr.hp) << endl;
						cout << "�T�{�O�_�ϥ�? 1:�O / 2:�_" << endl;
						int equip;
						cin >> equip;
						if (equip == 1) {
							if (chtr.hp == chtr.maxHp) {
								cout << "�ͩR�Ȥw��!�L���ɦ�!" << endl;
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
			cout << "��e���šG" << chtr.level << endl;
			cout << "�ثe�g���%�� : " << chtr.exp * 100 / chtr.levelExp << " %" << endl;
			cout << "��e�ͩR�O/�̤j�ͩR�O : " << chtr.hp << "/" << chtr.maxHp << endl;
			cout << "��e�]�O/�̤j�]�O : " << chtr.mp << "/" << chtr.maxMp << endl;
			cout << "��e�����O : " << chtr.atk << endl;
			break;
		}
		case 'k': {
			cout << endl << "�i�J��Ԥ�." << endl;
			Sleep(500);
			system("cls");
			cout << endl << "�i�J��Ԥ�.." << endl;
			Sleep(500);
			system("cls");
			cout << endl << "�i�J��Ԥ�..." << endl;
			Sleep(500);
			system("cls");
			cout << endl << "���J����!" << endl;
			Sleep(1000);
			system("cls");

			fightscene = 1;

			int chooseAorS = 0;
			cout << "�п�ܭn�ϥΧޯ�δ��q���� (1:���q���� / 2:�ޯ����) : ";
			cin >> chooseAorS;

			while (chtr.hp != 0 && mstTotalList[currentMonsterVectorPositionBuffer].hp != 0) {
				if (chooseAorS == 1) {
					mstTotalList[currentMonsterVectorPositionBuffer].hp -= chtr.atk;
					chtr.hp -= mstTotalList[currentMonsterVectorPositionBuffer].atk;

					cout << "�A�H�K�@���A�y���Ǫ� " << chtr.atk << "�I �ˮ`" << endl;
					cout << "�Ǫ����g�f�çq�A��A�y�� " << mstTotalList[currentMonsterVectorPositionBuffer].atk << "�I �ˮ`" << endl;

					Sleep(1000);

					cout << "�����q : ";
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
					cout << "�����]�O : ";
					float chtrmpslotlen = (float)chtr.maxMp / MAXBARLEN;
					int chtrmp = (int)ceil(chtr.mp / chtrmpslotlen);
					for (int i = 0; i < chtrmp; i++) {
						cout << "$";
					}
					cout << endl;
					cout << "�Ǫ���q : ";
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
						cout << i + 1 << ". " << map.skillName[i] << " ����: " << chtrSkillList[i].skillLevel << " ( ���m�� " << chtrSkillList[i].skillExp << " / 10 )" << endl;
					}
					cout << "�|���߱o�ޯ� : " << endl;
					for (int i = log2_log(chtr.level * 2); i < map.skillName.size(); i++) {
						cout << "���� : " << pow(2, i) << " �i�ǲ� " << map.skillName[i] << " �ޯ�C" << endl;
					}

					int skillChoice = 0;
					cout << "�п�ܷQ�ϥΤ��ޯ� : ";
					cin >> skillChoice;
					while (skillChoice - 1 > log2_log(chtr.level)) {
						cout << "�L���ޯ�i��!!�Э��s���!!" << endl;
						system("pause");
						cout << "�п�ܷQ�ϥΤ��ޯ� : ";
						cin >> skillChoice;
					}
					switch (skillChoice) {
					case 1: {
						if (chtr.mp < chtrSkillList[0].skillCost) {
							cout << "�]�O����������!!�L�k�ϥ�~~" << endl;
							system("pause");
							break;
						}

						mstTotalList[currentMonsterVectorPositionBuffer].hp -= chtrSkillList[0].skillPlus;
						chtr.mp -= chtrSkillList[0].skillCost;
						chtr.hp -= mstTotalList[currentMonsterVectorPositionBuffer].atk;
						chtrSkillList[0].skillExp++;
						cout << "��۩Ǫ� " << map.skillName[0] << " , ���y�� " << chtrSkillList[0].skillPlus << "�I �ˮ`, ��o 1 �I���m��" << endl;

						if (chtrSkillList[0].skillExp % 10 == 0) {
							chtrSkillList[0].skillLevel++;
							chtrSkillList[0].skillExp = 0;
							cout << endl;
							cout << "���ߧޯ�ɵ��o!!�W�[ " << chtrSkillList[0].skillPlus / 2 << " �ˮ`" << endl;
							chtrSkillList[0].skillPlus = chtrSkillList[0].skillPlus + chtrSkillList[0].skillPlus / 2;
						}
						cout << endl;
						cout << "�Ǫ����g�f�çq�A��A�y�� " << mstTotalList[currentMonsterVectorPositionBuffer].atk << "�I �ˮ`" << endl;
						Sleep(1000);

						cout << "�����q : ";
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
						cout << "�����]�O : ";
						float chtrmpslotlen = (float)chtr.maxMp / MAXBARLEN;
						int chtrmp = (int)ceil(chtr.mp / chtrmpslotlen);
						for (int i = 0; i < chtrmp; i++) {
							cout << "$";
						}

						cout << endl;

						cout << "�Ǫ���q : ";
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
							cout << "�]�O����������!!�L�k�ϥ�~~" << endl;
							system("pause");
							break;
						}
						mstTotalList[currentMonsterVectorPositionBuffer].hp -= chtrSkillList[1].skillPlus;
						chtr.mp -= chtrSkillList[1].skillCost;
						chtr.hp -= mstTotalList[currentMonsterVectorPositionBuffer].atk;
						chtrSkillList[1].skillExp++;
						cout << "��۩Ǫ� " << map.skillName[1] << " , ���y�� " << map.skillPlus[1] << "�I �ˮ`" << endl;
						if (chtrSkillList[1].skillExp % 10 == 0) {
							chtrSkillList[1].skillLevel++;
							chtrSkillList[1].skillExp = 0;
							chtrSkillList[1].skillPlus += chtrSkillList[1].skillPlus / 2;
							cout << "���ߧޯ�ɵ��o!!�W�[ " << chtrSkillList[1].skillPlus / 2 << " �ˮ`";
						}
						cout << "�Ǫ����g�f�çq�A��A�y�� " << mstTotalList[currentMonsterVectorPositionBuffer].atk << "�I �ˮ`" << endl;
						Sleep(1000);

						cout << "�����q : ";
						float chtrhpslotlen = (float)chtr.maxHp / MAXBARLEN;
						int chtrhp = (int)ceil(chtr.hp / chtrhpslotlen);
						for (int i = 0; i < chtrhp; i++) {
							cout << "@";
						}
						cout << "\t";
						cout << "�����]�O : ";
						float chtrmpslotlen = (float)chtr.maxMp / MAXBARLEN;
						int chtrmp = (int)ceil(chtr.mp / chtrmpslotlen);
						for (int i = 0; i < chtrmp; i++) {
							cout << "$";
						}

						cout << endl;

						cout << "�Ǫ���q : ";
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
							cout << "�]�O����������!!�L�k�ϥ�~~" << endl;
							system("pause");
							break;
						}
						mstTotalList[currentMonsterVectorPositionBuffer].hp -= chtrSkillList[2].skillPlus;
						chtr.mp -= chtrSkillList[2].skillCost;
						chtr.hp -= mstTotalList[currentMonsterVectorPositionBuffer].atk;
						chtrSkillList[2].skillExp++;
						cout << "��۩Ǫ� " << map.skillName[2] << " , ���y�� " << map.skillPlus[2] << "�I �ˮ`" << endl;
						if (chtrSkillList[2].skillExp % 10 == 0) {
							chtrSkillList[2].skillLevel++;
							chtrSkillList[2].skillExp = 0;
							chtrSkillList[2].skillPlus += chtrSkillList[2].skillPlus / 2;
							cout << "���ߧޯ�ɵ��o!!�W�[ " << chtrSkillList[2].skillPlus / 2 << " �ˮ`";
						}
						cout << "�Ǫ����g�f�çq�A��A�y�� " << mstTotalList[currentMonsterVectorPositionBuffer].atk << "�I �ˮ`" << endl;
						Sleep(1000);

						cout << "�����q : ";
						float chtrhpslotlen = (float)chtr.maxHp / MAXBARLEN;
						int chtrhp = (int)ceil(chtr.hp / chtrhpslotlen);
						for (int i = 0; i < chtrhp; i++) {
							cout << "@";
						}
						cout << "\t";
						cout << "�����]�O : ";
						float chtrmpslotlen = (float)chtr.maxMp / MAXBARLEN;
						int chtrmp = (int)ceil(chtr.mp / chtrmpslotlen);
						for (int i = 0; i < chtrmp; i++) {
							cout << "$";
						}

						cout << endl;

						cout << "�Ǫ���q : ";
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
							cout << "�]�O����������!!�L�k�ϥ�~~" << endl;
							system("pause");
							break;
						}
						mstTotalList[currentMonsterVectorPositionBuffer].hp -= chtrSkillList[3].skillPlus;
						chtr.mp -= chtrSkillList[3].skillCost;
						chtr.hp -= mstTotalList[currentMonsterVectorPositionBuffer].atk;
						chtrSkillList[3].skillExp++;
						cout << "��۩Ǫ� " << map.skillName[3] << " , ���y�� " << map.skillPlus[3] << "�I �ˮ`" << endl;
						if (chtrSkillList[3].skillExp % 10 == 0) {
							chtrSkillList[3].skillLevel++;
							chtrSkillList[3].skillExp = 0;
							chtrSkillList[3].skillPlus += chtrSkillList[3].skillPlus / 2;
							cout << "���ߧޯ�ɵ��o!!�W�[ " << chtrSkillList[3].skillPlus / 2 << " �ˮ`";
						}
						cout << "�Ǫ����g�f�çq�A��A�y�� " << mstTotalList[currentMonsterVectorPositionBuffer].atk << "�I �ˮ`" << endl;
						Sleep(1000);

						cout << "�����q : ";
						float chtrhpslotlen = (float)chtr.maxHp / MAXBARLEN;
						int chtrhp = (int)ceil(chtr.hp / chtrhpslotlen);
						for (int i = 0; i < chtrhp; i++) {
							cout << "@";
						}
						cout << "\t";
						cout << "�����]�O : ";
						float chtrmpslotlen = (float)chtr.maxMp / MAXBARLEN;
						int chtrmp = (int)ceil(chtr.mp / chtrmpslotlen);
						for (int i = 0; i < chtrmp; i++) {
							cout << "$";
						}

						cout << endl;

						cout << "�Ǫ���q : ";
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
							cout << "�]�O����������!!�L�k�ϥ�~~" << endl;
							system("pause");
							break;
						}
						mstTotalList[currentMonsterVectorPositionBuffer].hp -= chtrSkillList[4].skillPlus;
						chtr.mp -= chtrSkillList[4].skillCost;
						chtr.hp -= mstTotalList[currentMonsterVectorPositionBuffer].atk;
						chtrSkillList[4].skillExp++;
						cout << "��۩Ǫ� " << map.skillName[4] << " , ���y�� " << map.skillPlus[4] << "�I �ˮ`" << endl;
						if (chtrSkillList[4].skillExp % 10 == 0) {
							chtrSkillList[4].skillLevel++;
							chtrSkillList[4].skillExp = 0;
							chtrSkillList[4].skillPlus += chtrSkillList[4].skillPlus / 2;
							cout << "���ߧޯ�ɵ��o!!�W�[ " << chtrSkillList[4].skillPlus / 2 << " �ˮ`";
						}
						cout << "�Ǫ����g�f�çq�A��A�y�� " << mstTotalList[currentMonsterVectorPositionBuffer].atk << "�I �ˮ`" << endl;
						Sleep(1000);

						cout << "�����q : ";
						float chtrhpslotlen = (float)chtr.maxHp / MAXBARLEN;
						int chtrhp = (int)ceil(chtr.hp / chtrhpslotlen);
						for (int i = 0; i < chtrhp; i++) {
							cout << "@";
						}
						cout << "\t";
						cout << "�����]�O : ";
						float chtrmpslotlen = (float)chtr.maxMp / MAXBARLEN;
						int chtrmp = (int)ceil(chtr.mp / chtrmpslotlen);
						for (int i = 0; i < chtrmp; i++) {
							cout << "$";
						}

						cout << endl;

						cout << "�Ǫ���q : ";
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
					cout << "�L���ﶵ!!" << endl;
				}
				cout << "�п�ܭn�ϥΧޯ�δ��q���� (1:���q���� / 2:�ޯ����) : ";
				cin >> chooseAorS;
			}
			if (chtr.hp <= 0) {
				cout << "�԰�����...�^�쫰��!!";
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
				cout << "�԰��ӧQ!! ��o�g��� : " << randomExp << endl;
				chtr.exp += randomExp;
				if (chtr.exp > chtr.levelExp) {
					chtr.level++;
					chtr.levelExp += 50;
					chtr.exp = 0;
					cout << "���ߧA�I�ɵ��o�I�ثe���šG" << chtr.level << endl;
				}
				cout << "�������~ : " << allItemList[randomItem].itemName << "/ �������� : " << randomCoin << endl;
				cout << "�аݬO�_�ߨ� ? (1:�O/2:�_)";
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
			cout << "�L�����O!!" << endl;
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
					cout << "�D�J�Ǫ��I�O�_�i�J�԰�?" << endl;
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
						cout << "�A��ܹ�Ԫ��O : " << monsterVectorPositionX + 1 << ". " << mstTotalList[monsterVectorPositionX].name << endl;
					}

				}

			}
			else {
				system("cls");
			}
		}

		cout << "�п�J���O(w:�W/s:�U/a:��/d:�k/e:����/k:���[/c:�H�����A/m:�@�ɦa��/b:���}�I�]/f:���}):";
		cin >> chtr.movement;

	}// end of move while

	cout << "Exit!!!" << endl;
	system("pause");
	finPlayer.close();
	finMap.close();
	//ffout.close();
	return 0;
}




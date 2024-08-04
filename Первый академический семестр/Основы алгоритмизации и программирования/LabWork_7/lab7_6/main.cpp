#include <iostream>
#include <string>
#include "../staticlib/staticlib.h"

int const SIZE = 243;

long long powl(int n, int k) {
	if (k == 0) return 1;
	else return powl(n, k - 1) * n;
}
void cout_conversion(std::string str) {
	for (int i = 0; i < 5; i++) {
		std::cout << str[i];
	}
}
bool drink_barrel(int drink, int toxin) {
	return (toxin == drink) ? 0 : 1;
}

int main() {
	setlocale(LC_ALL, "ru");
	std::cout << "Задание выполнил Федорако Александр\nГруппа 353502\n";
	std::cout << "\n\n" << "Случилось это казалось так давно, но так недавно.\n";
	std::cout << "Патриций решил устроить праздник и для этого приготовил 240 бочек вина.\n";
	std::cout << "Однако к нему пробрался недоброжелатель по имени Пользователь,который подсыпал яд в одну из бочек.\n";
	std::cout << "Про яд известно, что человек, который его выпил, умирает в течение 24 часов.\n";
	std::cout << "До праздника осталось два дня, то есть 48 часов.\nУ патриция есть пять рабов, которыми он готов пожертвовать, чтобы узнать, в какой именно бочке яд.\n";
	std::cout << "Вы близкий друг Патриция и совершенно не хотите стать одним из тех рабов, что будут проверять вино на наличие яда.\n";
	int continuation = 1;
	while (continuation == 1) {
	int toxin = 0;
		std::cout << "Условия игры всем понятны, давайте же начнем...\n";
		std::cout << "Ну что пользователь, уже отравили бочку, не хотите поделиться секретом, введите отравленную бочку:";
		bool pop = 0;
		std::cin >> toxin;
		while(toxin > 240 || toxin < 0) {
			if (pop = 1) std::cout << "Пользователь, вы пытаетесь отравить бочку, в которой ничего нет?\nПридите в себя и сделайте пакость, пока вас не поймали!!!\nСтража уже за вашей спиной, введите отравленную бочку!:";
			std::cin >> toxin;
			pop = 1;
		}
		bool life_slaves[5]{ 1,1,1,1,1 };
		char str_result[6] = "00000";
		std::cout << "\nВот и начался первый день, до праздника 2 дня, пора действовать!\n";
		int life_rabs = 0;
		for (int i = 0; i < 5; i++) {
			if (life_slaves[i] == 1) life_rabs++;
		}
		std::cout << "На данный момент имеем " << life_rabs << " выживших рабов\n";
		std::cout << "Хм, хм, хм, мне кажется вы немного приболели, это не очень хорошо, ведь праздник так скоро.\n";
		std::cout << "Давайте же напоим рабов вином, только какими, это секрет, ведь хитрый пользователь не должен догатываться,что его план обречен\n";
		std::cout << "Ваш лечащий врач посоветовал вам принять лекарства и выспаться, чем вы и займетесь\n";
		for (int i = 1; i <= SIZE; i += 3) {
			life_slaves[4] = drink_barrel(i, toxin);
			if (life_slaves[4] == 0) break;
		}
		for (int i = 3; i < SIZE; i += 9) {
			for (int r = i; r < i + 3; r++) {
				if (life_slaves[3] == 0) break;
				life_slaves[3] = drink_barrel(r, toxin);
			}
		}
		for (int i = 9; i < SIZE; i += 27) {
			for (int r = i; r < i + 9; r++) {
				life_slaves[2] = drink_barrel(r, toxin);
				if (life_slaves[2] == 0) break;
			}
			if (life_slaves[2] == 0) break;
		}
		for (int i = 27; i < SIZE; i += 81) {
			for (int r = i; r < i + 27; r++) {
				if (life_slaves[1] == 0) break;
				life_slaves[1] = drink_barrel(r, toxin);
			}
			if (life_slaves[1] == 0) break;
		}
		for (int i = 81; i < 81 + 81; i++) {
			life_slaves[0] = drink_barrel(i, toxin);
			if (life_slaves[0] == 0) break;
		}
		for (int i = 0; i < 5; i++) {
			if (life_slaves[i] == 0) {
				str_result[4 - i] = '1';
			}
		}
		std::cout << "Вот и прошли сутки,вы выспаный и полны сил, давайте проверим сколько же там осталось рабов\n";
		life_rabs = 0;
		for (int i = 0; i < 5; i++) {
			if (life_slaves[i] == 1) life_rabs++;
		}
		std::cout << "На данный момент имеем " << life_rabs << " выживших рабов\n";
		std::cout << "Всем кажется что праздник обречен на провал, как бы ни так!\n";
		std::cout << "Времени медлить нет, давайте напоим рабов оставшимся вином!\n";
		std::cout << "Все очень переживают, а главное решение этой проблемы какое?) Конечно сон, как говориться утро вечера мудренее";
		for (int i = 2; i < SIZE && life_slaves[4] == 1; i += 3) {
			life_slaves[4] = drink_barrel(i, toxin);
		}
		for (int i = 6; i < SIZE && life_slaves[3] == 1; i += 9) {
			for (int r = i; r < i + 3 && life_slaves[3] == 1; r++) {
				life_slaves[3] = drink_barrel(r, toxin);
			}
		}
		for (int i = 18; i < SIZE && life_slaves[2] == 1; i += 27) {
			for (int r = i; r < i + 9 && life_slaves[2] == 1; r++) {
				life_slaves[2] = drink_barrel(r, toxin);
			}
		}
		for (int i = 54; i < SIZE && life_slaves[1] == 1; i += 81) {
			for (int r = i; r < i + 27 && life_slaves[1] == 1; r++) {
				life_slaves[1] = drink_barrel(r, toxin);
			}
		}
		for (int i = 162; i < SIZE && life_slaves[0] == 1; i++) {
			life_slaves[0] = drink_barrel(i, toxin);
		}

		for (int i = 0; i < 5; i++) {
			if (life_slaves[i] == 0 && str_result[4 - i] == '0') {
				str_result[4 - i] = '2';
			}
		}
		long long result = 0;
		for (int i = 4; i >= 0; i--) {
			result += powl(3, 4 - i) * ((int)(str_result[4 - i]) - '0');
		}
		life_rabs = 0;
		for (int i = 0; i < 5; i++) {
			if (life_slaves[i] == 1) life_rabs++;
		}
		std::cout << "\nВот и пришел день праздника, но что там у нас с рабами?\n";
		std::cout << "На данный момент имеем " << life_rabs << " выживших рабов\n";
		std::cout << "Но это не столь важно, что же у нас там с бочками, а с ними все просто отлично!\n";
		std::cout << "То, что это бочка под номером " << result << " должны знать только вы, ведь доверять в такой ситуации - себе дороже\n";
		std::cout << "Чтобы не произошло ничего непредвиденного, давайте уже выльем эту бочку, и обязательно сделаем это самостоятельно.\n";
		std::cout << "\n\n" << "Время не бесконечно, вот и настал долгожданный праздник, который прошел успешно, только благодаря вам!!!\n";
		std::cout << '\n' << "Не хотите поиздеваться над недображелателем еще раз?(1 - да, 2 - нет)\n";
		std::cout << "Введите продолжение:";
		std::cin >> continuation;
		std::cout << "\n\n";
	}
	std::cout << "Спасибо за внимание!!!";
}

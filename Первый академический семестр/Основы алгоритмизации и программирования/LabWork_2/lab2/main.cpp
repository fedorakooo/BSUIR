#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
	const int ZHURNAL = 24;
	setlocale(LC_ALL, "RU");
	std::cout << "Номер в журнале: " << ZHURNAL << "\n";
	int number;
	while (true)
	{
		std::cout << "\n\n";
		std::cout << "Введите номер задания: ";
		std::cin >> number;
		std::cout << "\n";
		if (number == 1)
		{
			std::cout << "Введите целочисленные значения x и y: ";
			int x, y;
			std::cin >> x >> y;
			std::cout << "\n";
			if (x != 0 && y != 0) {
				if (x % y == 0 || y % x == 0) {
					std::cout << "YES";
				}
				else {
					std::cout << "NO";
				}
				std::cout << "\n";
			}
			if (x == 0 && y != 0 || x != 0 && y == 0) {
				std::cout << "YES";
			}
			else if (x == 0 && y == 0) {
				std::cout << "ERROR";
			}
		}
		if (number == 2)
		{
			std::cout << "Введите действительные значения сторон треугольника: ";
			double a, b, c;
			std::cin >> a >> b >> c;
			std::cout << "\n";
			double min, middle, max;
			double cell;
			if (a > b) max = a, middle = b; else max = b, middle = a;
			if (c > middle) min = middle, middle = c; else min = c;
			if (middle > max) cell = max, max = middle, middle = cell;
			if (max < min + middle) std::cout << "YES"; else std::cout << "NO";
		}
		if (number == 3)
		{
			long int x, y;
			long double a, b, c, k;
			std::cout << "Введите значения переменных x y a b c k: ";
			std::cin >> x >> y;
			std::cin >> a >> b >> c >> k;
			std::cout << "\n";
			//1.1
			if (x == y) x = y = 0;
			else if (x > y) y = 0; else if (y > x) x = 0;
			long double max;
			if (a >= b) max = a; else max = b;
			if (c >= max) max = c;
			if (a == max) a = a - k;
			if (b == max) b = b - k;
			if (c == max) c = c - k;
			std::cout << x << ' ' << y << std::endl << a << ' ' << b << ' ' << c;
		}
		if (number == 4)
		{
			long double x, y;
			bool t = 0;
			std::cout << "Какую из вариантов решения вы хотите проверить?\n1.Если вы хотите проверить программу с использованием логического типа введите 1\n2.Если без логической переменной введите 2\nВведите вариант решения: ";
			int a;
			std::cin >> a;
			std::cout << "\n";
			if (a == 1) {
				std::cout << "Введите значения переменных x и y: ";
				std::cin >> x >> y;
				bool per = x > y;
				per = per ? x : per;
				std::cout << (per ? x : y);
			}
			if (a == 2) {
				std::cout << "Введите значения переменных x и y: ";
				std::cin >> x >> y;
				std::cout << (x > y ? x : y);
			}

		}
		if (number == 5)
		{
			long double K, X, Y;
			long double rast1, rast2, rast3, rast4;
			std::cout << "Введите значение переменных K X Y: ";
			std::cin >> K >> X >> Y;
			std::cout << "\n";
			if (K < 0) {
				K = -K;
				X = -X;
				Y = -Y;
			}
			//случай, когда точка не лежит не в Х, не в Y
			if ((X == 0 && (Y >= 0 && Y <= K)) || (X == K && (Y >= 0 && Y <= K)) || (Y == 0 && (X >= 0 && X <= K)) || (Y == K && (X >= 0 && X <= K))) {
				std::cout << std::setprecision(22) << 0;
				continue;
			}

			if (X >= 0 && X <= K && Y <= K && Y >= 0) {
				//случай, когда точка внутри
				rast1 = K - X; if (rast1 < 0) rast1 = -rast1;
				rast2 = K - Y; if (rast2 < 0) rast2 = -rast2;
				rast3 = X; if (rast3 < 0) rast3 = -rast3;
				rast4 = Y; if (rast4 < 0) rast4 = -rast4;
				//min
				long double minim;
				if ((rast4 <= rast3) && (rast4 <= rast2) && (rast4 <= rast1)) minim = rast4;
				else if ((rast3 <= rast4) && (rast3 <= rast2) && (rast3 <= rast1)) minim = rast4;
				else if ((rast2 <= rast3) && (rast2 <= rast4) && (rast2 <= rast1)) minim = rast4;
				else if ((rast1 <= rast3) && (rast1 <= rast2) && (rast1 <= rast1)) minim = rast4;
				std::cout << std::setprecision(22) << minim;
				continue;
			}
			//случай, когда точка лежит в промежутке Х, но не лежит в Y
			if (X >= 0 && X <= K) {
				rast1 = Y - K; if (rast1 < 0) rast1 = -rast1;
				rast2 = Y; if (rast2 < 0) rast2 = -rast2;
				long double minim;
				if (rast1 <= rast2) minim = rast1; else minim = rast2;
				std::cout << std::setprecision(22) << minim;
				continue;
			}
			//случай, когда точка лежит в промежутке Y, но не лежит в Х
			if (Y >= 0 && Y <= K) {
				rast1 = X - K; if (rast1 < 0) rast1 = -rast1;
				rast2 = X; if (rast2 < 0) rast2 = -rast2;
				long double minim;
				if (rast1 <= rast2) minim = rast1; else minim = rast2;
				std::cout << std::setprecision(22) << minim;
				continue;
			}
			if ((X <= 0 || X >= K) && (Y <= 0 || Y >= K)) {
				long double result;
				// 4 случая, в зависимости от четверти
				  // 1 четверть
				if (X >= K && Y >= K) {
					result = pow((X - K) * (X - K) + (Y - K) * (Y - K), 1 / 2);
					std::cout << std::setprecision(22) << result;
					continue;
				}
				//2 четверть
				if (X >= K && Y <= 0) {
					rast1 = X - K;
					rast2 = Y; if (rast2 < 0) rast2 = -rast2;
					std::cout << std::setprecision(22) << pow((rast1 * rast1) + (rast2 * rast2), 1 / 2);
					continue;
				}
				//3 четверть
				if (X <= 0 && Y <= 0) {
					rast1 = X; if (X < 0) X = -X;
					rast2 = Y; if (Y < 0) Y = -Y;
					std::cout << std::setprecision(22) << pow((rast1 * rast1) + (rast2 * rast2), 1 / 2);
					continue;
				}
				//4 четверть
				if (X <= 0 && Y >= K) {
					rast1 = X; if (rast1 < 0) rast1 = -rast1;
					rast2 = Y - K; if (rast2 < 0) rast2 = -rast2;
					std::cout << std::setprecision(22) << pow((rast1 * rast1) + (rast2 * rast2), 1 / 2);
					continue;
				}
			}
		}
		if (number == 6) {
			long double a, b, c, d;
			std::cout << "Введите значения переменных a b c d: ";
			std::cin >> a >> b >> c >> d;
			std::cout << "\n";
			if (c == 0) std::cout << "ERROR";
			else if (c >= d && a < d) {
				std::cout << std::setprecision(20) << a + (b / c);
			}
			else if (c < d && a >= d) {
				std::cout << std::setprecision(20) << a - (b / c);
			}
			else std::cout << 0 << "\n";
		}
		if (number == 8) {
			setlocale(LC_ALL, "ru");
			std::cout << "Какое из уравнений необходимо решить\n1.ax^4 + bx^2 + c = 0\n2.ax^4 + bx^3 + cx^2 + bx + a = 0\n3.x^3 + px + q = 0\nВведите номер уравнения:";
			int n;
			std::cin >> n;
			if (n == 1) {
				std::cout << "\nВведите значение коэффицентов a b c:";
				double a, b, c;
				std::cin >> a >> b >> c;
				double D = b * b - 4 * a * c;

				if (a == 0 && b == 0 && c == 0) {
					std::cout << "Корнями являются все действительные числа";
					continue;
				}
				else if (c == 0) {
					int nul = 0;
					double t;
					t = -b / a;
					if (t <= 0) {
						std::cout << nul;
						continue;
					}
					else {
						double x1 = sqrt(t);
						double x2 = -sqrt(t);
						std::cout << x2 << ' ' << nul << ' ' << x1;
					}
				}
				else if (a) {
					if (D < 0) {
						std::cout << "Нет корней";
					}
					else if (D == 0) {
						double t, x1, x2;
						t = -b / (2 * a);
						if (t == 0) {
							std::cout << 0;
							continue;
						}
						else if (t < 0) {
							std::cout << "Нет корней";
							continue;
						}
						else {
							x1 = sqrt(t);
							x2 = -sqrt(t);
							std::cout << x2 << ' ' << x1;
							continue;
						}
					}
					else {
						double t1 = (-b + sqrt(D)) / (2 * a);
						double t2 = (-b - sqrt(D)) / (2 * a);
						if (t1 < 0 && t2 < 0) {
							std::cout << "Нет корней";
							continue;
						}
						else if (t1 >= 0 && t2 < 0) {
							double x1 = sqrt(t1);
							double x2 = -sqrt(t1);
							std::cout << x1 << ' ' << x2;
							continue;
						}
						else if (t1 >= 0 && t2 >= 0) {
							double x1 = sqrt(t1);
							double x2 = -sqrt(t1);
							double x3 = sqrt(t2);
							double x4 = -sqrt(t2);
							std::cout << x2 << ' ' << x4 << ' ' << x3 << ' ' << x1;
							continue;
						}
						else if (t1 < 0 && t2 >= 0) {
							double x1 = sqrt(t2);
							double x2 = sqrt(t2) * (-1);
							std::cout << x1 << ' ' << x2;
							continue;
						}
					}
				}
				else {
					double t = -c / b;
					if (t < 0) {
						std::cout << "Нет корней";
						continue;
					}
					else if (t == 0) {
						std::cout << 0;
						continue;
					}
					else {
						double x1 = sqrt(t);
						double x2 = -sqrt(t);
						std::cout << x2 << ' ' << x1;
						continue;
					}
				}
			}
			if (n == 2) {
				std::cout << "\nВведите значение коэффицентов a b c:";
				double a, b, c;
				double t1, t2;
				std::cin >> a >> b >> c;
				double D = b * b - 4 * (-2 * a + c);
				if (a == 0 && b == 0 && c == 0) {
					std::cout << "Корнями являются все действительные числа";
					continue;
				}
				else if (a == 0) {
					//bt + c = 0
					double t = -c / b;
					if (t * t - 4 < 0) {
						std::cout << 0;
						continue;
					}
					else if (t * t - 4 == 0) {
						std::cout << 0 << ' ' << t / 2;
						continue;
					}
					else {
						double D = sqrt(t * t - 4);
						double x1 = (t - D) / 2;
						double x2 = (t + D) / 2;
						std::cout << 0 << ' ' << x1 << ' ' << x2;
						continue;
					}
				}
				else {
					double D = b * b - 4 * (-2 * a + c);
					if (D < 0) {
						std::cout << "Нет корней";
						continue;
					}
					t1 = (-b + sqrt(D)) / (2 * a);
					t2 = (-b - sqrt(D)) / (2 * a);
					if (t1 < 0 && t2 < 0) {
						std::cout << "Нет корней";
						continue;
					}
					else {
						double d1 = t1 * t1 - 4;
						double d2 = t2 * t2 - 4;
						if (d1 >= 0 && d2 < 0) {
							double x1 = (-t1 + sqrt(d1)) / 2;
							double x2 = (-t1 - sqrt(d1)) / 2;
							std::cout << x1 << " " << x2;
							continue;
						}
						else if (d1 < 0 && d2 >= 0) {
							double x1 = (-t2 + sqrt(d2)) / 2;
							double x2 = (-t2 - sqrt(d2)) / 2;
							std::cout << -x1 << " " << -x2;
							continue;
						}
						else {
							double x1 = (-t1 + sqrt(d1)) / 2;
							double x2 = (-t1 - sqrt(d1)) / 2;
							double x3 = (-t2 + sqrt(d2)) / 2;
							double x4 = (-t2 - sqrt(d2)) / 2;
							std::cout << x1 << " " << x2 << " " << x3 << " " << x4;
							continue;
						}
					}
				}
			}
			if (n == 3) {
				double p, q; // x^3 + px +q = 0  
				std::cout << "Введите значение p q:";
				std::cin >> p >> q;
				double Q = ((p * p * p / 27.0) + (q * q / 4.0));
				double pi = acos(0) * 2;
				if (Q >= 0) {
					double x1 = std::cbrt(-q / 2 + std::pow(Q, 0.5)) + std::cbrt(-(q / 2) - std::pow(Q, 0.5));
					std::cout << x1;
					continue;
				}
				else if (q == 0 && -p > 0) {
					double x1 = 0;
					double x2 = std::sqrt(-p);
					double x3 = -x2;
					std::cout << x1 << ' ' << x2 << ' ' << x3;
					continue;
				}
				if (Q < 0) {
					double Q = p / (-3.0);
					double R = (27.0 * q) / 54.0;
					double f = 1.0 / 3.0 * std::acos(R / std::sqrt(Q * Q * Q));
					double x1 = -2.0 * std::sqrt(Q) * std::cos(f);
					double x2 = -2.0 * std::sqrt(Q) * std::cos(f + (2.0 / 3.0) * pi);
					double x3 = -2.0 * std::sqrt(Q) * std::cos(f - (2.0 / 3.0) * pi);
					std::cout << x1 << ' ' << x2 << ' ' << x3;
					continue;
				}
			}
		}
		if (number == 7)
		{
			long double a, b, c;
			long int N;
			long double Y;
			std::cout << "Введите значения переменных a b c N: ";
			std::cin >> a >> b >> c >> N;
			std::cout << "\n";
			switch (N)
			{
			case 2:
				Y = b * c - pow(a, 2);
				break;
			case 56:
				Y = b * c;
				break;
			case 7:
				Y = pow(a, 2) + c;
				break;
			case 3:
				Y = a - b * c;
				break;
			default:
				Y = pow((a + b), 3);
				break;
			}
			std::cout << Y;
		}
		if (number == 9)
		{
			std::cout << "Номер выполняемого задания:" << ZHURNAL - 16;
			std::cout << "\n\n1.f(x) = 2x\n2.f(x) = x^3\n3.f(x) = x/3\nВведите значение функции f(x):";
			double x, z, a, c;
			int v;
			std::cin >> v;
			std::cout << "Введите значение переменной z:";
			std::cin >> z;
			std::cout << "Введите значение переменной a:";
			std::cin >> a;
			std::cout << "Введите значение переменной c:";
			std::cin >> c;
			if (z >= 0) x = 2 * z + 1;
			else x = log(z * z - z);
			double y;
			double fx = 1;
			switch (v) {
			case 1:
				std::cout << "Функция f(x) равна 2 * x\n";
				fx = 2 * x;
				std::cout << "f(x) = " << fx << "\n";
				break;
			case 2:
				std::cout << "Функция f(x) равна x^3\n";
				fx = x * x * x;
				std::cout << "f(x) = " << fx << "\n";
				break;
			case 3:
				std::cout << "Функция f(x) равна x/3";
				fx = x / 3;
				std::cout << "f(x) = " << fx << "\n";
				break;
			}
			y = sin(fx) * sin(fx) + a * pow(cos(x * x * x), 5) + c * log10(pow(x, 2 / 5));
			std::cout << "Значение y равно " << y << "\n";
		}
		if (number == 10) {
			double x1, y1, x2, y2, r, R;
			std::cout << "Введите значение координаты точки M1:";
			std::cin >> x1 >> y1;
			std::cout << "Введите радиус первой окружности:";
			std::cin >> r;
			std::cout << "Введите значение координаты точки M2:";
			std::cin >> x2 >> y2;
			std::cout << "Введите радиус второй окружности:";
			std::cin >> R;
			double l, x, y;
			if (x1 >= x2) x = x1 - x2;
			else x = x2 - x1;
			if (y1 >= y2) y = y1 - y2;
			else y = y2 - y1;
			l = pow(pow(x, 2) + pow(y, 2), 0.5);
			if (R > r && l < R && R > r + l) {
				std::cout << "\nДа";
				continue;
			}
			else if (r > R && r > R + l) {
				std::cout << "\nДа, но справедливо обратное для двух фигур";
				continue;
			}
			else if (l > R && l > r && l < R + r) {
				std::cout << "\nФигуры пересекаются";
				continue;
			}
			else std::cout << "\nНи одно условие не выполнено";
		}
		if (number == 11) {
			std::cout << "Введите значения переменных R P Q: ";
			long R, P, Q;
			long r;
			std::cin >> P >> R >> Q;
			r = P * sin(Q) / 2;
			std::cout << "\n";
			if (R <= r) std::cout << "YES";
			else std::cout << "NO";
		}
		if (number == 12) {
			std::cout << "Введите значение переменных a b c x y: ";
			long double a, b, c, x, y;
			std::cin >> a >> b >> c >> x >> y;
			std::cout << "\n";
			if (a <= 0 || b <= 0 || c <= 0 || x < 0 || y < 0)
			{
				std::cout << "Некорректный ввод";
			}
			else {
				long double max, middle, min;
				if (a >= b >= c) max = a, middle = b, min = c;
				else if (a >= c >= b) max = a, middle = c, min = b;
				else if (b >= a >= c) max = b, middle = a, min = c;
				else if (b >= c >= a) max = b, middle = c, min = a;
				else if (c >= a >= b) max = c, middle = a, min = b;
				else max = c, middle = b, min = a;
				long double rebroA, rebroB;
				rebroA = middle, rebroB = min;
				long double storonaA, storonaB;
				if (x >= y) storonaA = x, storonaB = y; else storonaA = y, storonaB = x;
				if (rebroA <= storonaA && rebroB <= storonaB) std::cout << "YES";
				else std::cout << "NO";
			}
		}
		if (number == 13)
		{
			long long int K;
			std::cout << "Введите количество найденных грибов: ";
			std::cin >> K;
			std::cout << "\n";
			long long int N = K;
			if (K < 0) N = -N;
			if (N % 10 == 1 && N % 100 != 11) {
				std::cout << "Мы нашли " << K << " гриб в лесу";
				continue;
			}
			else if (N % 10 >= 2 && N % 10 <= 4 && (N % 100 < 10 || N % 100 >= 20)) {
				std::cout << "Мы нашли " << K << " гриба в лесу";
				continue;
			}
			else {
				std::cout << "Мы нашли " << K << " грибов в лесу";
				continue;
			}
		}
		if (number == 14)
		{
			long double W, H, x1, x2, y1, y2, w, h;
			long double l1, l2, l;
			long double minX, minY;
			long double maxX, maxY;
			std::cout << "Введите значение переменных W H x1 y1 x2 y2 w h: ";
			std::cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
			std::cout << "\n";
			if (x1 > x2) minX = x2, maxX = x1; else minX = x1, maxX = x2;
			if (y1 > y2) minY = y2, minY = y1; else minY = y1, maxY = y2;
			long double j1, j2;
			if (x2 >= x1) j1 = x2 - x1; else j1 = x1 - x2;
			if (y2 >= y1) j2 = y2 - y1; else j2 = y1 - y2;
			if ((w + j1 > W) && (h + j2 > H)) {
				std::cout << "-1";
				continue;
			}
			else if (w <= x1 || h <= y1) {
				std::cout << "0";
				continue;
			}
			if (minX == 0 && maxX == W) {
				std::cout << h - minY;
				continue;
			}
			if (minY == 0 && maxY == H) {
				std::cout << w - minX;
				continue;
			}
			else {
				if (h >= minY) l2 = h - minY; else l2 = minY - h;
				if (w >= minX) l1 = w - minX; else l1 = minX - w;
				if (l2 <= l1) l = l2; else l = l1;
				std::cout << l;
				continue;
			}
		}
	}
}
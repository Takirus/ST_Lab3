#include <iostream>

using namespace std;

/**
 * \mainpage
 * @brief Класс Account наследуется от класса Client. Класс Client взаимодействует с классом Bank через метод openAccount().
 * \image{inline} html diagram.png "Связи"
 */

/**
 * @brief Класс, представляющий клиента банка
 */
class Client {
private:
    string name; /**< Имя */
    int id;      /**< Идентификатор клиента */

public:
    /**
     * @brief Конструктор класса Client
     * @param name Имя 
     * @param id Идентификатор клиента
     */
    Client(string name, int id) : name(name), id(id) {}

    /**
     * @brief Получение имени клиента
     * @return Имя клиента
     */
    string getName() const { return name; }

    /**
     * @brief Получение идентификатора клиента
     * @return Идентификатор 
     */
    int getId() const { return id; }
};

/**
 * @brief Класс, представляющий банковский счет
 */
class Account : public Client {
private:
    double balance; /**< Баланс на счете */

public:
    /**
     * @brief Конструктор класса Account
     * @param name Имя 
     * @param id Идентификатор
     * @param balance Баланс 
     */
    Account(string name, int id, double balance) : Client(name, id), balance(balance) {}

    /**
     * @brief Метод для получения баланса на счете
     * @return Баланс на счете
     */
    double getBalance() const { return balance; }

    /**
     * @brief Зачисление средств на счет
     * @param amount Сумма для зачисления
     */
    void deposit(double amount) { balance += amount; }

    /**
     * @brief Списания средств со счета
     * @param amount Сумма для списания
     */
    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        }
        else {
            cout << "Недостаточно средств на счете";
        }
    }
};

/**
 * @brief Класс, представляющий банк
 */
class Bank {
public:

    /**
    * @brief Открытие нового счета для клиента
    * @param client Клиент, для которого открывается счет
    * @param initialBalance Начальный баланс на счете
    */
    void openAccount(Client& client, double initialBalance) {
        cout << "Новый счёт клиента " << client.getName() << " с id " << client.getId();
        cout << "Баланс: " << initialBalance;
    }

    /**
    * @brief Получение информации о счете клиента
    * @param account Счет клиента
    */
    void getAccountInfo(Account& account) {
        cout << "\nИмя клиента: " << account.getName() << ",\n ID клиента: " << account.getId() << ",\n Баланс: " << account.getBalance();
    }

    /**
     * @brief Расчет суммы депозита
     * По формуле  \f$ A = P \times \left(1 + \frac{r}{n}\right)^{nt} \f$
     * @param P Начальная сумма 
     * @param r Годовая процентная ставка
     * @param n Сколько раз, проценты начисляются за год
     * @param t Количество лет, сколько деньги лежат на счете
     * @return Конечная сумма
     * \f$ A = P \times \left(1 + \frac{r}{n}\right)^{nt} \f$
     */
    double CalculateDeposit(double P, double r, int n, int t) {
        return P * pow(1 + r / n, n * t);
    }

};


int main() {
    setlocale(LC_ALL, "Russian");

    // Создание объекта банка
    Bank bank;

    Client client1("Иванов", 1001);
    Account account1("Иванов", 1001, 5000);

    // Открытие нового счета для клиента
    bank.openAccount(client1, 5000);

    // Получение информации о счете клиента
    bank.getAccountInfo(account1);

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
        class DBigInt {
            vector<unsigned char> vNum;
        public:
            DBigInt(unsigned num = 0) {
                vNum.clear();
                vNum.reserve(3000);
                if (num == 0)
                    vNum.push_back(0);
                while (num != 0) {
                    vNum.push_back(num % 10);
                    num /= 10;
                }
            }

            DBigInt operator+(const DBigInt &other) const {
                DBigInt result;
                unsigned i, j;
                unsigned char transport = 0;

                i = j = 0;
                result.vNum.clear();
                while (i < vNum.size() && j < other.vNum.size()) {
                    result.vNum.push_back((vNum[i] + other.vNum[j] + transport) % 10);
                    transport = (vNum[i] + other.vNum[j] + transport) / 10;
                    ++i;
                    ++j;
                }
                while (i < vNum.size()) {
                    result.vNum.push_back((vNum[i] + transport) % 10);
                    transport = (vNum[i] + transport) / 10;
                    ++i;
                }
                while (j < other.vNum.size()) {
                    result.vNum.push_back((other.vNum[j] + transport) % 10);
                    transport = (other.vNum[j] + transport) / 10;
                    ++j;
                }
                if (transport) {
                    result.vNum.push_back(transport);
                }
                return result;
            }

            operator string() const {
                string str;
                int i;
                for (i = vNum.size() - 1; i >= 0; --i)
                    str += '0' + vNum[i];

                return str;
            }

            bool operator==(const unsigned &num) const {
                DBigInt other(num);
                return *this == other;
            }

            bool operator==(const DBigInt &other) const {
                unsigned i;
                if (this->vNum.size() != other.vNum.size())
                    return false;
                for (i = 0; i < vNum.size(); ++i)
                    if (vNum[i] != other.vNum[i])
                        return false;
                return true;
            }

            DBigInt operator*(const unsigned &num) const {
                unsigned i;
                DBigInt result(0);
                for (i = 0; i < num; ++i)
                    result = result + (*this);
                return result;
            }

            static DBigInt fat(const unsigned &num){
                unsigned i;
                DBigInt myInt(1);

                for (i = 2; i <= num; ++i)
                    myInt = myInt * i;

                return myInt;
            }
        };
int main() {
    cout<<(string)(DBigInt::fat(1000));
    return 0;
}

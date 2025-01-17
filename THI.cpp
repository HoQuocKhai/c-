#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class Employee {
    static int counter; // Bi?n tinh d?m s? nhân viên
    string id, name, gender, dob, address, taxCode, contractDate;

public:
    Employee(string name, string gender, string dob, string address, string taxCode, string contractDate) {
        this->id = to_string(counter++);
        while (id.size() < 5) id = "0" + id; // T?o ID d? 5 ch? s?
        this->name = name;
        this->gender = gender;
        this->dob = dob;
        this->address = address;
        this->taxCode = taxCode;
        this->contractDate = contractDate;
    }

    friend ostream& operator<<(ostream& out, const Employee& e) {
        out << e.id << " " << e.name << " " << e.gender << " " 
            << e.dob << " " << e.address << " " 
            << e.taxCode << " " << e.contractDate;
        return out;
    }
};

int Employee::counter = 1;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // B? ký t? xu?ng dòng
    vector<Employee> employees;

    for (int i = 0; i < n; i++) {
        string name, gender, dob, address, taxCode, contractDate;
        getline(cin, name);
        getline(cin, gender);
        getline(cin, dob);
        getline(cin, address);
        getline(cin, taxCode);
        getline(cin, contractDate);

        employees.emplace_back(name, gender, dob, address, taxCode, contractDate);
    }

    for (const auto& e : employees) {
        cout << e << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> rotateMatrix(vector<vector<int>> matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> rotated(m, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rotated[j][n - 1 - i] = matrix[i][j];
        }
    }
    return rotated;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        vector<vector<int>> rotated = rotateMatrix(matrix);

        for (const auto& row : rotated) {
            for (int x : row) {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int minMergeToPalindrome(vector<int>& arr) {
    int l = 0, r = arr.size() - 1;
    int count = 0;

    while (l < r) {
        if (arr[l] == arr[r]) {
            l++;
            r--;
        } else if (arr[l] < arr[r]) {
            arr[l + 1] += arr[l];
            l++;
            count++;
        } else {
            arr[r - 1] += arr[r];
            r--;
            count++;
        }
    }

    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << minMergeToPalindrome(arr) << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    string id, name, clazz, email;

    void input() {
        cin >> id;
        cin.ignore();
        getline(cin, name);
        cin >> clazz >> email;
    }

    string getDepartment() const {
        return id.substr(4, 4);
    }

    bool isExcluded() const {
        return clazz[0] == 'E';
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<Student> students(n);
    for (int i = 0; i < n; i++) {
        students[i].input();
    }

    int q;
    cin >> q;
    cin.ignore();

    vector<string> queries(q);
    for (int i = 0; i < q; i++) {
        getline(cin, queries[i]);
    }

    for (const string& query : queries) {
        string department;
        if (query == "Ke toan") department = "DCKT";
        else if (query == "Cong nghe thong tin") department = "DCCN";
        else if (query == "An toan thong tin") department = "DCAT";
        else if (query == "Vien thong") department = "DCVT";
        else if (query == "Dien tu") department = "DCDT";

        cout << "DANH SACH SINH VIEN NGANH " << query << ":\n";
        for (const auto& student : students) {
            if (student.getDepartment() == department && !student.isExcluded()) {
                cout << student.id << " " << student.name << " "
                     << student.clazz << " " << student.email << endl;
            }
        }
    }

    return 0;
}
class Employee:
    counter = 1  # Static counter for generating employee IDs

    def __init__(self, name, gender, dob, address, tax_code, contract_date):
        self.id = f"{Employee.counter:05d}"
        self.name = name
        self.gender = gender
        self.dob = dob
        self.address = address
        self.tax_code = tax_code
        self.contract_date = contract_date
        Employee.counter += 1

    def __str__(self):
        return f"{self.id} {self.name} {self.gender} {self.dob} {self.address} {self.tax_code} {self.contract_date}"

if __name__ == "__main__":
    n = int(input())
    employees = []
    for _ in range(n):
        name = input().strip()
        gender = input().strip()
        dob = input().strip()
        address = input().strip()
        tax_code = input().strip()
        contract_date = input().strip()
        employees.append(Employee(name, gender, dob, address, tax_code, contract_date))
    
    for emp in employees:
        print(emp)
def rotate_matrix(matrix):
    return [list(row) for row in zip(*matrix[::-1])]

if __name__ == "__main__":
    t = int(input())
    results = []
    for _ in range(t):
        n, m = map(int, input().split())
        matrix = []
        elements = list(map(int, input().split()))
        for i in range(n):
            matrix.append(elements[i*m:(i+1)*m])
        rotated = rotate_matrix(matrix)
        results.append(rotated)
    
    for rotated in results:
        for row in rotated:
            print(" ".join(map(str, row)))

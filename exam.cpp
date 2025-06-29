#include <iostream>
#include <vector>
#include <cstring>
#include <clocale>

using namespace std;



class studentInformation{
 public:
  string studentName;
  string studentSurname;
  void registration();
  int studentNumber;
  int correctCounter = 0;
  int wrongCounter = 0;
  int successPercent= 0;	
  void startExam();
  void showInformation();
};

vector<studentInformation> students;

void studentInformation::registration(){
	
	int counter;
	
	cout << "Kaç öğrenci kayıt edilecek: ";
	cin >> counter;
	
	cout << endl;
	
	for(int i = 0;i<counter;i++){
			
	studentInformation newStudent;
	
	cout << "Kayıt yapılacak öğrencinin ismini giriniz: ";
	cin >> newStudent.studentName;
	
	cout << "Kayıt yapılacak öğrencinin soyismini giriniz: ";
	cin >> newStudent.studentSurname;
	
	cout << "Kayıt yapılacak öğrencinin numarasını giriniz: ";
	cin >> newStudent.studentNumber;
	
	cout << endl;
	
	students.push_back(newStudent);

}
}

void studentInformation::startExam(){
	
	string name;
	string surname;
	int number;
	char option;

   correctCounter = 0;
   wrongCounter = 0;
   successPercent = 0;

	cout << "Lütfen isminizi giriniz: ";
	cin >> name;
	
	cout << "Lütfen soyisminizi giriniz: ";
	cin >> surname;
	
	cout << "Lütfen numaranızı giriniz: ";
	cin >> number;
	
	cout << endl;
	
	bool found = false;
	
	for(int x = 0; x<students.size() ;x++){
		
		if (students[x].studentName == name && students[x].studentSurname == surname && students[x].studentNumber == number){
			
			found = true; 
			
			cout << "Doğrulama Başarılı..." << endl;
			cout << endl;
			
			cout << "1. Aşağıdakilerden hangisinin otoyolda sürülmesi yasaktır?" << endl;
			cout << "A) Motosiklet" << endl;
			cout << "B) Bisiklet" << endl;
			cout << "C) Çekici" << endl;
			cout << "D) Otobüs" <<endl;
			cout << "Cevabınız : ";
			cin >> option;
			
			if(option == 'b' || option == 'B')
			correctCounter++;
		    else
		    wrongCounter++;
		
		    cout << endl;
		
			cout << "2. Karşıdan gelen araçla karşılaşıldığında uzağı gösteren ışıkların yerine hangisi yakılmalıdır?" << endl;
		    cout << "A) Yakını gösteren ışıklar" << endl;
	     	cout << "B) Acil uyarı ışıkları" << endl;
	    	cout << "C) Dönüş ışıkları" << endl;
	    	cout << "D) Park ışıkları" << endl;
	    	cout << "Cevabınız : ";
			cin >> option;
			
			if(option == 'a' || option == 'A')
			correctCounter++;
		    else
		    wrongCounter++;
		    
		    cout << endl;
		
		    cout << "3. Motor çok sıcak iken radyatöre soğuk su konulması aşağıdakilerden hangisine sebep olur?" << endl;
		    cout << "A) Motorun stop etmesine" << endl;
	    	cout << "B) Motor gücünün artmasına" << endl;
	    	cout << "C) Motor bloğunun çatlamasına" << endl;
	    	cout << "D) Motor sıcaklığının artmasına" << endl;
			cout << "Cevabınız : ";
			cin >> option;
		    
		    if(option == 'c' || option == 'C')
			correctCounter++;
		    else
		    wrongCounter++;
		    
		    cout << endl;
		    
		    cout << "4. Aşağıdakilerden hangisi çıkıklarda yapılan ilk yardım uygulamalarındandır?" <<endl;
		    cout << "A) Kazazedenin hareket ettirilmesi" <<endl;
		    cout << "B) Çıkığın yerine oturtulmaya çalışılması" <<endl;
		    cout << "C) Çıkığın alt bölgesindeki deri rengi, ısı ve nabzın kontrol edilmesi" <<endl;
		    cout << "D) Eklemin düzeltildikten sonra tespit edilmesi" <<endl;
		    cout << "Cevabınız : ";
			cin >> option;
			
			if(option == 'c' || option == 'C')
			correctCounter++;
		    else
		    wrongCounter++;
		    
		    cout << endl;
		    
		    cout << "5. Aşağıdaki parçalardan hangisi arızalandığında motor yağında su, soğutma suyunda yağ olduğu gözlenir?" << endl;
		    cout << "A) Piston" << endl;
		    cout << "B) Kam mili" << endl;
		    cout << "C) Krank mili" << endl;
		    cout << "D) Silindir kapak contası" << endl;
		    cout << "Cevabınız : ";
			cin >> option;
			
			if(option == 'd' || option == 'D')
			correctCounter++;
		    else
		    wrongCounter++;
		    
		    cout << endl;
		    
		    successPercent = 20*correctCounter;
		    
		    cout << "Tebrikler sınavı bitirdiniz..";
		    cout << endl;
		    cout << "Doğru sayısı: " << correctCounter << endl;
		    cout << "Yanlış saıysı: " << wrongCounter << endl;
		    cout << "Başarı Yüzdesi: %" << successPercent << endl;
		    cout << endl;
		    
		    students[x].correctCounter = correctCounter;
		    students[x].wrongCounter = wrongCounter;
		    students[x].successPercent = successPercent;
		    
			break;	    
		}	
			
	}
	
	
	if(found == false)
	cout << "Girilen bilgiler yanlış!!" << endl;
	

}

void studentInformation::showInformation(){
	
	int number;
	
	cout << "Sonucunu öğrenmek istediğiniz öğrencinin numarasını giriniz: ";
	cin >> number;
	
	cout << endl;
	
	bool isFind = false;
	
	for(int y = 0;y<students.size();y++){
		if(students[y].studentNumber == number){
			
			isFind = true;
			
			cout << "İsim: " << students[y].studentName << endl;
			cout << "Soyisim: " << students[y].studentSurname << endl;
			cout << "Numara: " << students[y].studentNumber << endl;
			cout << "Doğru sayısı: " << students[y].correctCounter << endl;
			cout << "Yanlış sayısı: " << students[y].wrongCounter << endl;
			cout << "Başarı Yüzdesi: %" << students[y].successPercent << endl;
			
			cout << endl;
			
			if(students[y].successPercent >= 70)
			cout << "Tebrikler sınavı geçtiniz.." << endl;
			else 
			cout << "Sınavdan kaldınız.." << endl;
			
			cout << endl;
			
		}
}

if(isFind == false){
cout << "Aradığınız öğrenci bulunamadı!" << endl;
cout << endl;
}
}

void console(){
	
	
	cout << "****** EHLİYET SINAVI ******" << endl;
	cout << "1- Öğrenci Kayıt" << endl;
	cout << "2- Sınava başla" << endl;
	cout << "3- Bilgileri görüntüle" << endl;
	cout << "4- Çıkış" << endl;
	cout << endl;
	
}

int main() {
	
setlocale(LC_ALL,"Turkish");
	
studentInformation choose;
int selection = 0;


	do{
		
	console();
		
	cout << "Yapmak istediğiniz işlemi seçiniz: ";
	cin >> selection;
		
		if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Geçersiz giriş! Lütfen sadece sayı giriniz." << endl;
            continue; 
        }	
	
	cout << endl;
	
switch(selection){
	
	case 1:
		choose.registration();	
	break;
	
	case 2:
		choose.startExam();
	break;
	
	case 3:
	    choose.showInformation();	
	break;
	
	case 4:
		cout << "Çıkış yapılıyor..." << endl;
	break;
	
	default:
		cout << "Yanlış seçim yaptınız!" << endl;
	
}
	
	
}while(selection != 4);
	
	
	return 0;
}
	
		


	




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void sleeptracker();
void moodtracker();
void videocall();
void chat();
void userProfile();
void sdcProfile();
void meditation();
void toLowerCase(char str[]);
int cekusn(char usn[]);

typedef struct{
	char username[50];
	char password[50];
	char name[100];
	char date[15];
	char email[100];
}mindwell;

mindwell data;
mindwell temp;





void home() {
    int choice;
    system("cls");
   do{ printf("\n\n\n\n\n==========HOME============\n");
    printf("Welcome, %s! Hope you feel good today!\n", data.name);
    printf("1. User Profile\n");
    printf("2. SDC Profile\n");
    printf("3. Meditation\n");
    printf("4. Video call\n");
    printf("5. Chat\n");
    printf("6. Mood Tracker\n");
    printf("7. Sleep Tracker\n");
    printf("0. Logout\n");
    printf("Enter your choice (number): ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            userProfile();
            break;
        case 2:
            sdcProfile();
            break;
        case 3:
            meditation();
            break;
        case 0:
            printf("\nLogout successful!\n");
            exit(0);
            break;
        case 4:{
            system("cls");
            videocall();
            break;
        }
        case 5:{
            system("cls");
            chat();
            break;
        }

        case 6:{
            system("cls");
            moodtracker();
            break;
        }

        case 7:{
            system("cls");
            sleeptracker();
            break;
        }   

        default:
            printf("Invalid choice.\n");
            printf("\nPress enter to continue..."); getchar(); getchar();
            system("cls");
            break;
    }
   }while (choice!=0);
}


void toLowerCase(char str[]) {
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

// Function to authenticate user login
int loginUser() {
     system("cls");
    int i;
    mindwell matcha[1000];
    char username[50], password[50];
    char usn[50];
    char u[50], p[50];
    FILE *fp;
    int loginSuccess = 0; // Flag to indicate whether login was successful

    do {
        fp = fopen("users.txt", "r");
        if (fp == NULL) {
            printf("Error in opening file.\n");
            return -1;
        }
        printf("\n\n\n==========LOGIN PAGE============\n");
        printf("Enter Username: ");
        scanf("%49s", username); // Limit input length to prevent buffer overflow
        toLowerCase(username);
        strcpy(usn, username);
        printf("Enter Password: ");
        scanf("%49s", password); // Limit input length to prevent buffer overflow
        i=0;
        while (fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", u, p, matcha[i].name, matcha[i].date, matcha[i].email) == 5) {
            if (strcmp(username, u) == 0 && strcmp(password, p) == 0) {
                loginSuccess = 1; // Set flag to indicate successful login
                break;
            }
            i++;
        }

        if (!loginSuccess) { // If login was not successful
            printf("\nLogin failed: Incorrect username or password.\n");
        }

        fclose(fp);
    } while (!loginSuccess); // Repeat until login is successful


    //isi struct dgn data org yg login
    strcpy(data.username, usn);
    strcpy(data.password, password);
    strcpy(data.name, matcha[i].name);
    strcpy(data.date, matcha[i].date);
    strcpy(data.email, matcha[i].email);

    home();


    return 1; // Return 1 if login successful
}

int cekusn(char usn[]) {
    char username[50];
    FILE *fp;

    fp = fopen("users.txt", "r");
    if (fp == NULL) {
        printf("Error in opening file.\n");
        return -1;
    }

    while (fscanf(fp, "%[^,]", username) != EOF) { // Parse the username from each line
        if (strcmp(username, usn) == 0) {
            fclose(fp);
            return 1; // Return 1 if username already exists
        }
        fscanf(fp, "%*[^\n]"); // Skip the rest of the line
    }
    fclose(fp);
    return 0; // Return 0 if username doesn't exist
}

void registerUser() {
     system("cls");
    char usn[50];
    char username[50], password[50];
    FILE *fp;

    fp = fopen("users.txt", "a");
    if (fp == NULL) {
        printf("Error in opening file.\n");
        return;
    }
    printf("\n\n\n==========REGISTER PAGE============\n");
    do {
        printf("Enter Username: ");
        scanf("%49s", username);
        toLowerCase(username);
        strcpy(usn, username);

        if (cekusn(usn) == 1) {
            printf("\nUsername already exists. Choose another username.\n");
        }
    } while (cekusn(usn) == 1); // Keep asking for a username until a unique one is entered

    strcpy(data.username, usn);

    printf("Enter Name: ");
    scanf(" %[^\n]", data.name); getchar();

    printf("Enter register date (DD/MM/YY):");
    scanf(" %[^\n]", data.date); getchar();

    printf("Enter email:");
    scanf(" %[^\n]", data.email); getchar();

    printf("Enter Password: ");
    scanf("%s", data.password); getchar();

    fprintf(fp, "%s,%s,%s,%s,%s\n", data.username, data.password, data.name, data.date, data.email);
    fclose(fp);

    printf("\n\nRegistration successful!\n");
    printf("\nReturning to main menu...\n\n");
    printf("\nPress enter to continue..."); getchar();
}


int main() {
    system("cls");
    int choice;

    do {
        printf("==========WELCOME TO MINDWELL============");
        printf("\n\n");
        printf("Let's start your journey to a better mental health! <3\n\n");
        printf("1. Register\n2. Login\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            registerUser();
        } 
        else if (choice == 2) {
            int status = loginUser();

            if (status == 0) {
                printf("\nLogin failed: Incorrect username or password.\n");
            }
        } 
        else if (choice == 3) {
            printf("Exiting...\n");
            exit(0);
        } 
        else {
            printf("\nInvalid choice.\n");
            printf("\nPress enter to continue..."); getchar(); getchar();
            system("cls");
        }
    } while (choice != 3);

    return 0;
}




void editProfile(){
    system("cls");
    int choice;
    do {
        system("cls");
        printf("\n\n\n==========EDIT PROFILE============\n");
        printf("Name: %s\n", data.name);
        printf("Username: %s\n", data.username);
        printf("Register Date: %s\n", data.date);
        printf("Email: %s\n", data.email);
        printf("==================================\n");

        mindwell matcha[1000];

        printf("1. Edit Name\n");
        printf("2. Edit Password\n");
        printf("3. Edit Email\n");
        printf("4. Back\n");
        printf("Enter your choice (number): ");
        scanf("%d", &choice); getchar(); 

        switch (choice) {
            case 1:{
                printf("Enter new name: ");
                scanf(" %[^\n]", temp.name); getchar();
            

            FILE *fp;
            fp = fopen("users.txt", "r");
            if (fp == NULL) {
                printf("Error in opening file.\n");
                return;
            }

            int i=0; 
                while (!feof(fp)) {
                    fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", matcha[i].username, matcha[i].password, 
                    matcha[i].name, matcha[i].date, matcha[i].email);
                    i++;    
                }
                fclose(fp);

            for (int j=0; j<i; j++){
                if (strcmp(matcha[j].username, data.username)==0){
                    strcpy(matcha[j].name, temp.name);
                }
            }
            strcpy(data.name, temp.name);

            fp= fopen("users.txt", "w");
            for (int j=0; j<i; j++){
                fprintf(fp, "%s,%s,%s,%s,%s\n", matcha[j].username, matcha[j].password, 
                matcha[j].name, matcha[j].date, matcha[j].email);
            }
            fclose(fp);
            printf("\nEdit successful!\n");
            printf("\nPress enter to continue..."); getchar();
            break;
        }


        case 2:{
            do{
            printf("Enter old password:");
            scanf(" %[^\n]", temp.password); getchar();
            if (strcmp(temp.password, data.password)!=0){
                printf("Wrong password!\n");
                printf("\nPress enter to continue..."); getchar();
                system("cls");
            }
            }while (strcmp(temp.password, data.password)!=0);


            printf("Enter new password: ");
            scanf("%[^\n]", temp.password); getchar();

            FILE *fp;
            fp = fopen("users.txt", "r");
            if (fp == NULL) {
                printf("Error in opening file.\n");
                return;
            }

            int i=0;
            while (!feof(fp)) {
                fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", matcha[i].username, matcha[i].password, 
                matcha[i].name, matcha[i].date, matcha[i].email);
                i++;    
                }
            fclose(fp);

            for (int j=0; j<i; j++){
                if (strcmp(matcha[j].username, data.username)==0){
                    strcpy(matcha[j].password, temp.password);
                }
            }

            strcpy(data.password, temp.password);

            fp= fopen("users.txt", "w");
            for (int j=0; j<i; j++){
                fprintf(fp, "%s,%s,%s,%s,%s\n", matcha[j].username, matcha[j].password, 
                matcha[j].name, matcha[j].date, matcha[j].email);
            }
            fclose(fp);
            printf("\nEdit successful!\n");
            printf("\nPress enter to continue..."); getchar();
            break;
        }


        case 3:{
            printf("Enter new email: ");
            scanf(" %[^\n]", temp.email); getchar();
            
            FILE *fp;
            fp = fopen("users.txt", "r");
            if (fp == NULL) {
                printf("Error in opening file.\n");
                return;
            }

            int i=0;
            while (!feof(fp)) {
                fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", matcha[i].username, matcha[i].password, 
                matcha[i].name, matcha[i].date, matcha[i].email);
                i++;    
                }
            fclose(fp);

            for (int j=0; j<i; j++){
                if (strcmp(matcha[j].username, data.username)==0){
                    strcpy(matcha[j].email, temp.email);
                }
            }
            strcpy(data.email, temp.email);

            fp= fopen("users.txt", "w");
            for (int j=0; j<i; j++){
                fprintf(fp, "%s,%s,%s,%s,%s\n", matcha[j].username, matcha[j].password, 
                matcha[j].name, matcha[j].date, matcha[j].email);
            }

            printf("\nEdit successful! Confirmation email has been sent to %s\n", temp.email);
            printf("\nPress enter to continue..."); getchar();
            fclose(fp);
            break;
        }

        case 4:{
                userProfile();
                break;
            }
        }
    } while (choice != 4); // Repeat until the user chooses to go back
}


void userProfile(){
    system("cls");
	printf("\n\n\n==========USER PROFILE============\n");
	printf("Name: %s\n", data.name);
	printf("Username: %s\n", data.username);
	printf("Register Date: %s\n", data.date);
	printf("Email: %s\n", data.email);
	printf("==================================\n");

	printf("1. Edit Profile\n");
	printf("2. Back\n");
	int choice;
	printf("Enter your choice (number): ");
	scanf("%d", &choice);
	switch (choice) {
		case 1:
			editProfile();
			break;
		case 2:
			home();
			break;
	}
}





void sdcProfile() {
     system("cls");
    printf("\n\n\n==========SDC PROFILE============\n");
    printf("Syarat dan ketentuan:\n");
    printf("1. Permintaan Rujukan: Beberapa psikiater mungkin mengharuskan pasien memiliki rujukan dari dokter umum atau profesional kesehatan lain sebelum menerima konsultasi.\n");
    printf("2. Jadwal Janji: Pasien biasanya perlu membuat janji terlebih dahulu untuk konsultasi dengan psikiater. Kebanyakan psikiater menerima janji melalui telepon atau lewat situs web atau aplikasi resmi.\n");
    printf("3. Informasi Identitas: Pasien harus memberikan informasi identitas yang akurat, termasuk nama, alamat, nomor telepon, dan data kontak lainnya. Ini diperlukan untuk keperluan administratif dan komunikasi.\n");
    printf("4. Informasi Medis: Pasien harus memberikan riwayat medis yang akurat dan lengkap, termasuk catatan tentang masalah kesehatan mental yang telah dialami, pengobatan sebelumnya, dan penggunaan obat-obatan.\n");
    printf("5. Batal atau Ubah Janji: Jika perlu membatalkan atau mengubah janji, pasien biasanya harus memberi tahu psikiater dalam waktu yang cukup lama sebelum janji tersebut.\n");
    printf("6. Privasi dan Kerahasiaan: Psikiater berkewajiban untuk menjaga kerahasiaan informasi yang dibagikan oleh pasien selama sesi konsultasi. Ini adalah prinsip etika yang sangat penting dalam praktik psikiatri.\n");
    printf("7. Etika dan Perilaku: Pasien diharapkan untuk menjaga perilaku yang sesuai selama sesi konsultasi dan menghormati psikiater serta staf lainnya.\n");
    printf("8. Kerjasama dengan Pengobatan: Pasien diharapkan untuk berkomunikasi secara jujur dengan psikiater dan mengikuti panduan dan rekomendasi yang diberikan dalam pengobatan mereka.\n");
    printf("9. Keamanan: Jika psikiater memiliki kekhawatiran tentang bahaya diri sendiri atau orang lain yang mungkin dilakukan oleh pasien, mereka dapat memiliki kewajiban hukum untuk melaporkan ke pihak berwenang.\n");
    printf("10. Pemutusan Hubungan: Baik pasien maupun psikiater memiliki hak untuk mengakhiri hubungan profesional jika diperlukan. Psikiater biasanya akan memberi pemberitahuan yang cukup waktu jika mereka memutuskan untuk menghentikan perawatan.\n");
    printf("11. Evaluasi Lanjutan: Psikiater dapat merekomendasikan evaluasi atau perawatan lanjutan, termasuk terapi atau pengobatan lainnya, jika dianggap perlu.\n");
    printf("Harap diingat bahwa syarat dan ketentuan ini dapat berbeda antara praktek-praktek psikiater, sehingga penting untuk mendiskusikannya dengan psikiater yang Anda pilih sebelum mulai sesi konsultasi.\n");
    printf("==================================\n\n");

    printf("\nPress enter to continue..."); getchar(); getchar();
     system("cls");
}




void meditation() {
     system("cls");
    int choice;
    do {
    printf("\n\n\n==========MEDITATION============\n");
    printf("1. Meditation for Sadness\n");
    printf("2. Meditation for Anger\n");
    printf("3. Meditation for Worry\n");
    printf("4. Meditation for Stress\n");
    printf("5. Meditation for Insomnia\n");
    printf("0. Back to home\n\n");

    
    printf("Enter your choice (number): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            printf("Meditation for Sadness\n");
            char* meditation_steps[] = {
                "Temukan tempat yang tenang dan nyaman untuk duduk.",
                "Tutup mata dan fokus perlahan pada pernafasan.",
                "Rasakan aliran udara masuk dan keluar dari tubuhmu.",
                "Biarkan pikiranmu datang dan pergi tanpa menilainya.",
                "Sentuh titik-titik rasa di tubuhmu, mulai dari ujung jari hingga ujung kepala.",
                "Fokus pada suara di sekitarmu tanpa terikat padanya.",
                "Kenali perasaan dan emosi tanpa terikat padanya.",
                "Visualisasikan tempat damai dalam pikiranmu, seperti pantai atau hutan.",
                "Biarkan dirimu meresapi kedamaian dan ketenangan tersebut.",
                "Buka mata perlahan dan lanjutkan hari dengan ketenangan yang baru ditemukan."
            };

            // Cetak langkah-langkah meditasi
            printf("Langkah-langkah Meditasi:\n");
            for (int i = 0; i < sizeof(meditation_steps) / sizeof(meditation_steps[0]); ++i) {
                printf("%d. %s\n", i + 1, meditation_steps[i]);
            }
            printf("\nPress enter to continue..."); getchar(); getchar();
             system("cls");
            break;
        }

        case 2: {
            printf("Meditation for Anger\n");
            char* anger_management_steps[] = {
                "Temukan tempat yang tenang dan nyaman untuk duduk.",
                "Ambil napas dalam-dalam, masukkan melalui hidung dan keluarkan melalui mulut.",
                "Akui perasaan kemarahan tanpa penilaian.",
                "Hitung hingga sepuluh dengan perlahan, beri diri Anda waktu untuk tenang.",
                "Fokus pada merilekskan setiap bagian tubuh, mulai dari jari kaki hingga kepala.",
                "Visualisasikan suasana yang tenang dan damai untuk mengalihkan perhatian.",
                "Ulangi mantra atau frase yang menenangkan pada diri sendiri.",
                "Pertimbangkan perspektif orang lain atau situasi tersebut.",
                "Terapkan komunikasi tegas daripada reaksi agresif.",
                "Beri diri Anda waktu dan ruang sebelum merespons, berikan ruang untuk reaksi yang lebih dipertimbangkan."
            };

            // Cetak langkah-langkah meditasi pengelolaan kemarahan
            printf("Langkah-langkah Meditasi Pengelolaan Kemarahan:\n");
            for (int i = 0; i < sizeof(anger_management_steps) / sizeof(anger_management_steps[0]); ++i) {
                printf("%d. %s\n", i + 1, anger_management_steps[i]);
            }
            printf("\nPress enter to continue..."); getchar(); getchar();
             system("cls");
            break;
        }

        case 3: {
            printf("Meditation for Worry\n");
            char* worry_management_steps[] = {
                "Carilah tempat yang tenang untuk duduk dengan nyaman.",
                "Fokus pada pernapasan, ambil napas dalam-dalam dan buang secara perlahan.",
                "Akui kekhawatiran tanpa membiarkan diri terbawa olehnya.",
                "Bayangkan diri Anda melepaskan kekhawatiran seperti daun yang terbawa arus sungai.",
                "Fokus pada saat ini dan terima keadaan dengan penuh kesadaran.",
                "Rilekskan tubuh Anda dari ujung kepala hingga ujung kaki.",
                "Pikirkan solusi yang mungkin untuk masalah, tanpa larut dalam kekhawatiran.",
                "Ulangi mantra positif untuk menenangkan pikiran Anda.",
                "Beri diri Anda izin untuk melepaskan kontrol atas hal-hal yang tidak dapat Anda ubah.",
                "Buka mata perlahan dan lanjutkan hari dengan ketenangan pikiran."
            };

            // Cetak langkah-langkah meditasi pengelolaan kekhawatiran
            printf("Langkah-langkah Meditasi Pengelolaan Kekhawatiran:\n");
            for (int i = 0; i < sizeof(worry_management_steps) / sizeof(worry_management_steps[0]); ++i) {
                printf("%d. %s\n", i + 1, worry_management_steps[i]);
            }
            printf("\nPress enter to continue..."); getchar(); getchar();
             system("cls");
            break;
        }

        case 4: {
            printf("Meditation for Stress\n");
            char* stress_management_steps[] = {
                "Cari tempat yang tenang dan nyaman untuk duduk.",
                "Ambil napas dalam-dalam, tahan sebentar, dan lepaskan perlahan-lahan.",
                "Fokus pada perasaan di tubuh Anda, sadari ketegangan dan lepaskan.",
                "Bayangkan diri Anda berada di tempat yang tenang dan damai.",
                "Rilekskan satu per satu bagian tubuh, mulai dari ujung kaki hingga kepala.",
                "Fokus pada pikiran positif dan menggantikan pikiran stres dengan afirmasi positif.",
                "Ulangi kata-kata yang menenangkan atau mantra yang Anda pilih.",
                "Bayangkan diri Anda mengatasi tantangan dengan tenang dan penuh keyakinan.",
                "Terima dan hargai momen sekarang tanpa khawatir akan masa depan.",
                "Buka mata perlahan dan lanjutkan hari dengan ketenangan dan ketegangan yang berkurang."
            };

            // Cetak langkah-langkah meditasi pengelolaan stres
            printf("Langkah-langkah Meditasi Pengelolaan Stres:\n");
            for (int i = 0; i < sizeof(stress_management_steps) / sizeof(stress_management_steps[0]); ++i) {
                printf("%d. %s\n", i + 1, stress_management_steps[i]);
            }
            printf("\nPress enter to continue..."); getchar(); getchar();
             system("cls");
            break;
        }

        case 5: {
            printf("Meditation for Insomnia\n");
            char* insomnia_management_steps[] = {
        
				"Ciptakan lingkungan tidur yang nyaman dan gelap.",
                "Ambil napas dalam-dalam dan perlahan, fokus pada pernafasan Anda.",
                "Rilekskan satu per satu bagian tubuh Anda, mulai dari kaki hingga kepala.",
                "Bayangkan diri Anda berada di tempat yang tenang dan nyaman.",
                "Hindari melihat jam dan pikirkan hal-hal yang menenangkan daripada kekhawatiran tidur.",
                "Jauhi perangkat elektronik setidaknya 30 menit sebelum tidur.",
                "Gunakan teknik meditasi pernapasan untuk menenangkan pikiran.",
                "Jika Anda tidak bisa tidur, bangun dan lakukan aktivitas yang tenang hingga Anda merasa mengantuk.",
                "Buka mata perlahan dan bersiap untuk tidur dengan rasa tenang.",
                "Terima dan hargai momen tidur Anda."
            };

            // Cetak langkah-langkah meditasi pengelolaan insomnia
            printf("Langkah-langkah Meditasi Pengelolaan Insomnia:\n");
            for (int i = 0; i < sizeof(insomnia_management_steps) / sizeof(insomnia_management_steps[0]); ++i) {
                printf("%d. %s\n", i + 1, insomnia_management_steps[i]);
            }
            printf("\nPress enter to continue..."); getchar(); getchar();
             system("cls");
            break;
        }
        case 0: {
            home();
            system("cls");
            break;
        }

        default:
            {printf("Pilihan tidak valid.\n"); break;}
    }
    } while (choice!=0);

}



void videocall(){
    system("cls");
    printf("============VIDEO CALL============\n\n");
    printf("1. Dr. Jesslyn\n");
    printf("2. Dr. Nando\n");
    printf("3. Dr. Bintang\n");
    printf("4. Dr. Haidar\n");

    int choice;
    printf("Enter your choice (number): ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("\nCalling Dr Jesslyn...\n");
            printf("\nPress enter to continue..."); getchar(); getchar();
            system("cls");
            printf("Video call session has ended\n");
            printf("\nPress enter to continue..."); getchar(); 
            system("cls");
            break;
        case 2:
            printf("\nCalling Dr. Nando...\n");
            printf("\nPress enter to continue..."); getchar(); getchar();
            system("cls");
            printf("Video call session has ended\n");
            printf("\nPress enter to continue..."); getchar(); 
            system("cls");
            break;
        case 3:
            printf("\nCalling Dr Bintang...\n");
            printf("\nPress enter to continue..."); getchar(); getchar();
            system("cls");
            printf("Video call session has ended\n");
            printf("\nPress enter to continue..."); getchar(); 
            system("cls");
            break;
        case 4:
            printf("\nCalling Dr Haidar...\n");
            printf("\nPress enter to continue..."); getchar(); getchar();
            system("cls");
            printf("Video call session has ended\n");
            printf("\nPress enter to continue..."); getchar(); 
            system("cls");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}


void chat(){
    system("cls");
    printf("============CHAT============\n\n");
    printf("1. Dr. Jesslyn\n");
    printf("2. Dr. Nando\n");
    printf("3. Dr. Bintang\n");
    printf("4. Dr. Haidar\n");

    int choice;
    printf("Enter your choice (number): ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("\nChatting with Dr Jesslyn...\n");
            printf("\nPress enter to continue..."); getchar(); getchar();
            system("cls");
            printf("Chat session has ended\n");
            printf("\nPress enter to continue..."); getchar(); 
            system("cls");
            break;
        case 2:
            printf("\nChatting with Dr. Nando...\n");
            printf("\nPress enter to continue..."); getchar(); getchar();
            system("cls");
            printf("Chat session has ended\n");
            printf("\nPress enter to continue..."); getchar(); 
            system("cls");
            break;
        case 3:
            printf("\nChatting with Dr Bintang...\n");
            printf("\nPress enter to continue..."); getchar(); getchar();
            system("cls");
            printf("Chat session has ended\n");
            printf("\nPress enter to continue..."); getchar(); 
            system("cls");
            break;
        case 4:
            printf("\nChatting with Dr Haidar...\n");
            printf("\nPress enter to continue..."); getchar(); getchar();
            system("cls");
            printf("Chat session has ended\n");
            printf("\nPress enter to continue..."); getchar(); 
            system("cls");
            break;
        default:
            printf("Invalid choice.\n");
    }
}


void moodtracker(){
    int mood, choice;
    do {
        system("cls");
        printf("============MOOD TRACKER============\n\n");
        printf("1. Track your mood today\n");
        printf("2. Mood graph\n");
        printf("3. Back\n");
        printf("Enter your choice (number): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("On a scale from 1 to 5, how do you feel today?\n");
                printf("Your mood>>\n");
                scanf("%d", &mood);
                printf("Successfully recorded your mood!\n");
                printf("\nPress enter to continue..."); getchar(); getchar();
                system("cls");
                break;
            case 2:
                printf("(Displaying mood graph)\n");
                printf("\nPress enter to continue..."); getchar(); getchar();
                system("cls");
                break;
            case 3:
                home();
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 3);
    
}

void sleeptracker(){
    int sleep, choice;
    do {
        system("cls");
        printf("============SLEEP TRACKER============\n\n");
        printf("1. Track your sleep today\n");
        printf("2. Sleep graph\n");
        printf("3. Back\n");
        printf("Enter your choice (number): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("How many hours did you sleep last night?\n");
                printf("Your sleep>>\n");
                scanf("%d", &sleep);
                printf("Successfully recorded your sleep!\n");
                printf("\nPress enter to continue..."); getchar(); getchar();
                system("cls");
                break;
            case 2:
                printf("(Displaying sleep graph)\n");
                printf("\nPress enter to continue..."); getchar(); getchar();
                system("cls");
                break;
            case 3:
                home();
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 3);
}

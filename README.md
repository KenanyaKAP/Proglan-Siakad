# Proglan-Siakad
Sistem Informasi Akademik
Kenanya Keandra A P
Teknik Komputer
5024211004

# Laporan Sederhana

## Perubahan
- Mengubah tampilan program
- Menambahkan sistem user login page, sehingga admin, tendik, dosen, dan mahasiswa bisa memiliki tampilannya sendiri-sendiri.
- Menambahkan class Data, Departemen, Matkul, dan FRS
- Menambahkan function class / namespace Utils (Utilities) untuk function general yang diperlukan dalam pembuatan program
- Menambahkan function class / namespace Save yg berguna untuk menyimpan semua data dari program, mulai dari data id, user, dosen, tendik, mahasiswa, dan lain-lain. Sehingga semua data yg disimpan akan di load kembali saat program dijalankan (Menggunakan library FSTREAM)
- Class Data digunakan untuk menyimpan data - data penting terakhir seperti id dari instance class yang terakhir dibuat
- Class Departemen berisi daftar mata kuliah yang ada di departemen tersebut, serta seluruh dosen dan mahasiswanya
- Class Matkul berisi nama dan kode dari mata kuliah tersebut
- Class FRS berisikan daftar matkul apa saja yang telah di enroll ke mahasiswa, juga memuat nilai matkul tersebut

## Cara Menggunakan
- Login menggunakan default username dan password (admin/Admin)
- Tambah Departemen terlebih dahulu pada menu "Tampilkan Departemen"
- Selanjutnya bisa mengisikan daftar mata kuliah yang ada di departemen tersebut pada menu "Tampilkan Semua Mata Kuliah > Tambah Mata Kuliah"
- Selanjutnya bisa langsung mengisikan data Dosen dan mahasiswa pada menu "Tampilkan Semua Mahasiswa > Tambah Mahasiswa"
- Saat menambahkan mahasiswa, FRS untuk mahasiswa tersebut akan secara otomatis terbuat
- Untuk mengisi / enroll kelas dari mahasiswa, admin harus mengubah masa FRS terlebih dahulu pada menu "8. MENU ADMIN > 1. Ubah Masa Pendidikan"
- Masa FRS: Belum Masa FRS > Pengisian FRS > Lewat Masa FRS
- Setelah masa berubah menjadi Pengisian FRS, baik Admin, Dosen, atau Mahasiswa dapat mengenroll kelas yang sudah ada ke FRS milik mahasiswa, pada menu "Tampilkan FRS > Tambah Kelas"
- FRS Mahasiswa harus disetujui terlebih dahulu, bisa oleh admin, ataupun dari dosen wali mahasiswa tersebut
- Setelah semua FRS sudah disetujui, admin bisa mengubah masa FRS menjadi "Lewat Masa FRS"
- Pada masa ini, baik dosen atau admin bisa mengisikan nilai dari mahasiswa pada menu "Isi Nilai Mahasiswa"
- Setelah semua FRS Mahasiswa sudah memiliki nilai (IPS), admin bisa melanjutkan untuk mengubah Tahun Pendidikan (Mengubah Semester)
- IPS dan IPK dari setiap mahasiswa akan nampak pada menu Mahasiswa

## Mekanisme Program
- Sistem Save dan Load dibuat menggunakan library FSTREAM. File data menggunakan extension .bin di folder data/. Sebelumnya di tulis ke file, data di encrpt terlebih dahulu dengan pada function Utils::encrypt. Dan saat di load, data di decrpyt terlebih dahulu pada function Utils::decrpyt.
- Terdapat global variable yaitu Data, vector<User>, vector<Departemen>, vector<Matkul>, vector<Dosen>, vector<Tendik>, vector<Mahasiswa>, dan vector<FRS>. Pada awal fungsi main, semua variable tersebut akan diisi oleh function Save::load(). Dan bila terjadi perubahan pada data, function Save::save() akan dilakukan agar data langsung tersimpan.
- Data / variable yang dilempar dan ditangkap pada function, rata-rata sudah berpusat pada global variable, karena hampir seluruh parameter yang dilempar pada setiap function adalah pointer. Sehingga akan mengubah data asli pada global variable.
- Seluruh class terhubung dengan menggunakan id. Dan bila memerlukan instance dari suatu class, sudah terdapat static function pada setiap class untuk mengambil instance dari class tersebut (getClassById()).

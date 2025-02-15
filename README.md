🚌 **Kırklareli İçin Toplu Taşıma Güzergah Planlama**

Bu proje, Kırklareli'nin 3 farklı mahallesi için toplu taşıma hattı planlaması yapmak amacıyla Softmax algoritmasını kullanır. Mahalleler; nüfus yoğunluğu, mevcut ulaşım altyapısı, maliyet analizi, çevresel etki ve sosyal fayda kriterlerine göre değerlendirilir.


## 🧠 **Proje Amacı**

Toplu taşıma güzergahlarının planlanmasında, mahallelerin taşıma hattına uygunluk oranlarını hesaplamak için Softmax algoritması kullanılmıştır. Bu sayede, en uygun güzergah belirlenir ve maliyet-fayda analizi yapılır.

## 🛠️ **Kullanılan Teknolojiler**

- **C Programlama Dili**
- **Softmax Algoritması**
- **Yapılar (struct)**
- **Bellek Yönetimi (malloc/free)**

## ⚙️ **Çalışma Prensibi**

Program, her mahalle için belirlenen kriterleri ağırlıklandırır ve Softmax algoritması kullanarak her mahalleye bir uygunluk skoru atar. Mahalleler, uygunluk skorlarına göre sıralanır ve en uygun güzergah önerilir.

## 📋 **Kriter Ağırlıkları**

- 🏙️ **Nüfus Yoğunluğu:** %40
- 🚍 **Mevcut Ulaşım Altyapısı:** %20
- 💰 **Maliyet Analizi:** %10
- 🌿 **Çevresel Etki:** %15
- 🤝 **Sosyal Fayda:** %15


## 🖥️ **Örnek Çıktı**

Kırklareli'nin mahalleleri için toplu taşıma hattı uygunluk oranları (Softmax sonuçları):

Karakaş: 0.423456

İstasyon: 0.251234

Demirtaş: 0.325310



Önerilen toplu taşıma güzergahı (Softmax'e göre en uygun sırayla):
1. Karakaş (Uygunluk: 0.423456)
2. Demirtaş (Uygunluk: 0.325310)
3. İstasyon (Uygunluk: 0.251234)


## 📖 **Algoritma Açıklaması**

Program, mahallelerin uygunluk skorlarını hesaplamak için Softmax algoritmasını kullanır:

- Her mahalle için ağırlıklı kriter toplamı hesaplanır.
- Softmax fonksiyonuyla bu değerlere 0 ile 1 arasında oranlar atanır.
- Mahalleler, bu oranlara göre azalan sıralamada gösterilir.



 ⚠️ **Hata Durumları**

- Bellek tahsis hatası durumunda program uyarı verir ve işlemi sonlandırır.


🚀 İyi çalışmalar! 😊


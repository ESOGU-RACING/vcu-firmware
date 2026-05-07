# vcu-firmware
Formula Student aracımızın ana kontrol ünitesi (VCU) yazılımı. Sensör verilerinin işlenmesi, CAN Bus haberleşmesi ve güvenlik (SCS) protokollerini içerir.

# 🧠 VCU Firmware (Vehicle Control Unit)

Bu depo, ESOGÜ Racing aracının "beyni" olan ana kontrol yazılımını barındırır. 

## 🚀 Planlanan Fonksiyonlar
- **Data Acquisition:** Gaz/Fren pedalları ve direksiyon açısı sensörlerinin okunması.
- **CAN Bus Communication:** Aracın tüm birimleri arasındaki dijital veri akışının yönetimi.
- **Safety Critical Signals (SCS):** Kural kitabına tam uyumlu güvenlik yazılımı.
- **Drive Modes:** Endurance ve Acceleration etapları için farklı sürüş haritaları.

## 🛠️ Teknik Altyapı
- **Microcontroller:** STM32 (Mimari netleşince güncellenecek)
- **Framework:** PlatformIO / C++

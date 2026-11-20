# Arduino Strobe Light

Program efek lampu *strobe* berbasis Arduino Uno. Sistem bekerja secara otomatis memilih 4 pola kedipan LED acak dengan jeda waktu (*timing*) acak menggunakan fungsi `random()`.

## Konfigurasi Hardware

- **Microcontroller:** Arduino Uno (atau sejenisnya)
- **Output:** 5x LED
- **Pinout:**
  - LED 1 : Pin Digital `8`
  - LED 2 : Pin Digital `9`
  - LED 3 : Pin Digital `10`
  - LED 4 : Pin Digital `11`
  - LED 5 : Pin Digital `12`
- **Floating Analog Pin:** `A0` (digunakan untuk memicu `randomSeed`)

---

## Analisis Pola Kedipan (Logic Flow)

Setiap siklus `loop()`, program akan memilih salah satu dari 4 fungsi pola berikut secara acak:

1. **`strobeSerempak()`**
   - **Efek:** 5 LED menyala dan padam secara bersamaan (*flash* serempak).
   - **Timing:** 30–80 ms per kedipan (diulang 3–7 kali).

2. **`kedipAcakSatuSatu()`**
   - **Efek:** Hanya 1 LED acak yang melompat-lompat menyala secara cepat.
   - **Timing:** Nyala 40–100 ms, jeda 10–40 ms (diulang 5–11 kali).

3. **`kedipAcakBeberapa()`**
   - **Efek:** Kombinasi acak beberapa LED menyala bersamaan dalam 1 langkah (*random binary matrix*).
   - **Timing:** Berganti pola tiap 50–120 ms (diulang 4–8 kali).

4. **`sapuanCepat()`**
   - **Efek:** Pola berjalan beruntun dari Pin 8 → 12 lalu kembali 12 → 8.
   - **Timing:** 25–60 ms per langkah LED (diulang 1–2 kali putaran).

---

## 🛠️ Cara Penggunaan

1. Open `strobe_led.ino` di Arduino IDE.
2. Hubungkan 5 LED (gunakan resistor pembatas arus yang sesuai) ke pin 8, 9, 10, 11, dan 12.
3. Biarkan pin `A0` tidak terhubung ke apapun agar pembacaan noise acak optimal.
4. Upload kode ke board Arduino.

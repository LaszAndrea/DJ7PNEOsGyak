# 🧩 Operációs Rendszerek – Gyakorlati Feladatok

Ez a repository az *Operációs Rendszerek* egyetemi tárgy gyakorlati anyagait tartalmazza. A gyakorlatok során Linux rendszereken dolgoztunk, C nyelven írtunk programokat, és megismerkedtünk az operációs rendszerek belső működésével.

## 💻 Tartalom

### 🖥️ Linux és C nyelvű feladatok

- Alap Linux parancsok gyakorlása
- C nyelvű programok, amelyek:
  - 👪 Gyermek és szülő processzeket hoznak létre
  - ⏱️ CPU ütemezési algoritmusokat modelleznek (FCFS, SJF, Round Robin)
  - ⏰ Alarm-ok és signal handlerek használata
  - 🔗 Pipe-ok és named pipe-ok (FIFO)
  - 📬 Üzenetsorok és szemaforok kezelése

### 📂 Féléves projekt

- Létrehoz egy gyermek processzt
- A gyermek processz végrehajtja a `/bin/ls -R/` parancsot paraméterekkel
- A gyermek visszatér egy 0-tól különböző értékkel
- A szülő processz megvárja a gyermek végét, majd kiírja a visszatérési értéket
- A feladathoz részletes dokumentáció (PDF) is tartozik

## 🚀 Használat

A C programok Linux környezetben fordíthatók és futtathatók:
```bash
gcc program.c -o program
./program

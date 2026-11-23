# Second Year — Term 2 Projects & Improvement

مستودع تعليمي يجمع أعمال وتمارين الفصل الثاني من السنة الثانية في مجالات البرمجة وعلوم الحاسوب. يشمل المستودع واجبات ومحاضرات وتطبيقات صفية ومشاريع مصغرة وتحديات خوارزميات بلغات وأدوات متعددة.

المستودع مناسب للمراجعة والتعلم الذاتي وإعادة تشغيل الأمثلة، وليس مشروعًا واحدًا يضم مسار بناء موحدًا. لكل قسم أدواته ومتطلبات تشغيله الخاصة.

## محتويات المستودع

| المجلد | المحتوى |
| --- | --- |
| `AI/` | أمثلة ومحاضرات الذكاء الاصطناعي، برمجة Python، NumPy وPandas، ودفاتر Jupyter (`.ipynb`) |
| `Algorithms/` | حلول وتمارين خوارزميات وهياكل بيانات، تشمل Java وC++ وPython وJavaScript ولغات أخرى |
| `Operating System/` | تطبيقات صفية وواجبات Python، وتشمل خوارزميات جدولة المعالج مثل FCFS وSJF وSRTF |
| `Oracle DB/` | نصوص SQL لتطبيقات قواعد بيانات Oracle، واجبات الصف، واستعلامات بيانات |
| `web devolpment/` | أمثلة تطوير ويب بسيطة باستخدام HTML وJavaScript وCSS |
| `.vscode/` | إعدادات مهام ومسارات محرر Visual Studio Code |

## بنية المجلدات

```text
.
├── AI/
│   ├── All Lectures/
│   ├── homework/
│   └── on lap/
├── Algorithms/
│   ├── challenges/
│   ├── homework/
│   └── on lap/
├── Operating System/
│   ├── homework/
│   └── on lap/
├── Oracle DB/
│   ├── homework/
│   ├── on lap/
│   └── projects/
├── web devolpment/
│   ├── homework/
│   └── on lap/
├── .editorconfig
├── .vscode/
├── ignore.git
└── Second year Term 2 projects & improve.code-workspace
```

## التقنيات واللغات المستخدمة

- Python ودفاتر Jupyter
- C++ وJava وJavaScript وC#
- Kotlin وRuby وHaskell وScala وRust
- Oracle SQL وOracle Database
- HTML وCSS وJavaScript
- VS Code وملفات مساحة العمل الخاصة به

تختلف الاحتياجات باختلاف الملف؛ لا يشترط توفير جميع أدوات اللغات لتصفح المستودع أو العمل على قسم واحد فقط.

## المتطلبات العامة

اختر الأدوات المناسبة للقسم الذي ستعمل عليه:

- Git لاستنساخ المستودع.
- Python لتشغيل ملفات `.py` ودفاتر Jupyter.
- محرر نصوص أو Visual Studio Code لتصفّح المشروع وتشغيل أمثلة الويب.
- مترجم C++ مثل GCC أو Clang لتجميع برامج C++.
- JDK لتجميع وتشغيل ملفات Java.
- Node.js لتشغيل أمثلة JavaScript خارج المتصفح عند الحاجة.
- بيئة Oracle Database وعميل Oracle مناسب لتشغيل ملفات `.sql`.

لا يوجد ملف إدارة تبعيات موحد أو ملف إعداد مشروع شامل حاليًا. يجب تثبيت حزم Python المطلوبة يدوياً عند تشغيل كل دفتر أو برنامج.

## البدء

1. استنسخ المستودع:

   ```powershell
   git clone https://github.com/dheyaaldrasi/Second-year-Term-2-projects---improve.git
   cd "Second-year-Term-2-projects---improve"
   ```

2. افتح المجلد في Visual Studio Code:

   ```powershell
   code .
   ```

3. اختر الملف المطلوب من الأقسام أعلاه، ثم شغّله باستخدام الأدوات المرتبطة بامتداده.

## أمثلة التشغيل

### Python

لتشغيل ملف Python، افتح الطرفية داخل مجلد الملف أو استخدم مسارًا نسبيًا:

```powershell
python "AI\on lap\lap3.py"
python "Operating System\on lap\FCFS.py"
```

يمكن تشغيل دفاتر Jupyter ببيئة تدعمها، مثل JupyterLab أو VS Code:

```powershell
jupyter lab
```

من ثم افتح أي ملف `.ipynb` داخل مجلد `AI/`.

عند ظهور خطأ مرتبط بمكتبة ناقصة، ثبّت المكتبة اللازمة لكل البرنامج، مثل NumPy أو Pandas، في بيئة Python المستخدمة:

```powershell
python -m pip install numpy pandas jupyter
```

### C++

```powershell
g++ "Algorithms\homework\training\LinkedList.cpp" -o LinkedList.exe
.\LinkedList.exe
```

قد يلزم تعديل أمر التجميع حسب وجود مترجم ومكتبات إضافية في الملف المستهدف.

### Java

```powershell
javac "Algorithms\challenges\week1_programming_challenges\1_sum_of_two_digits\APlusB.java"
java -cp "Algorithms\challenges\week1_programming_challenges\1_sum_of_two_digits" APlusB
```

قد يختلف اسم الفئة الرئيسية بين الأمثلة.

### JavaScript

افتح ملفات HTML مباشرة في المتصفح، أو استخدم ملحق Live Server في VS Code:

```text
web devolpment/homework/hw_1/index.html
```

لتشغيل ملفات JavaScript مستقلة يدعمها Node.js:

```powershell
node "Algorithms\challenges\week1_programming_challenges\1_sum_of_two_digits\APlusB.js"
```

### Oracle SQL

افتح ملفات `.sql` باستخدام Oracle SQL Developer أو عميل Oracle متوافق آخر، واتصل بقاعدة بياناتك، ثم نفّذ النصوص بحسب ترتيب المشروع والاعتماديات.

ملف مشروع Oracle الأساسي موجود في:

```text
Oracle DB/projects/My_Oracle_Project/
```

تحقّق من بيانات الاتصال واسم المستخدم والنظام قبل تنفيذ أي نص.

## ملاحظات حول المحتوى

- مجلدات ومسارات الجامعة والمحاضرات قد تحتوي أسماءً عربية أو مسافات.
- توجد إصدارات ملفات تنفيذية مبنية مسبقًا للمثال في بعض أقسام Algorithms؛ يفضّل إعادة التجميع من المصدر عند اختلاف نظام التشغيل أو المعمارية.
- ملف `ignore.git` يحتوي قواعد تجاهل خاصة بهذا المستودع ويُنصح بمراجعته قبل إعادة تكوين إعدادات Git.
- لا تنفذ نصوص قاعدة البيانات على بيئة إنتاجية دون مراجعتها وضبط البيانات الوصفية والصلاحيات أولًا.

## المساهمة

يمكنك المساهمة بتحسين ترتيب المحتوى أو إضافة شرح وتشغيل أو إصلاح الأخطاء في الأمثلة. عند إضافة عمل جديد، حافظ قدر الإمكان على تقسيم المجلدات الموجود:

```text
المادة/
├── All Lectures/
├── homework/
├── on lap/
└── projects/
```

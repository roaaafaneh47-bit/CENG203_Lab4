CENG203 Lab 4 — شرح سريع
1) احفظي نسخة احتياطية من مجلد مشروعك الحالي C:\CENG203\CENG203_Lab.
2) افتحي ZIP وانسخي المجلدات Labs, LinkedList, Stack, Queue وملف main.cpp إلى C:\CENG203\CENG203_Lab، ووافقي على الاستبدال فقط بعد أخذ نسخة احتياطية. لا تمسحي ملف المشروع .vcxproj أو .slnx.
3) داخل Visual Studio → Solution Explorer → على اسم المشروع CENG203_Lab كليك يمين → Add → Existing Item.
4) أضيفي ملفات .cpp الخمسة التالية (يمكن تحديد عدة ملفات باستخدام Ctrl):
   Labs\Week04.cpp
   Stack\Stack.cpp
   Stack\ArrayStack.cpp
   Queue\Queue.cpp
   Queue\CircularQueue.cpp
5) إذا ظهر week04.cpp قديم ضمن Source Files: كليك يمين عليه → Remove فقط، ثم أضيفي النسخة الجديدة من Labs\Week04.cpp. لا تختاري Delete.
6) تأكدي أن main.cpp مضاف مرة واحدة فقط؛ لا تضيفي main.cpp ثانيًا. إذا استبدلت ملف main.cpp الموجود، احتفظي بالنسخة الوحيدة المرتبطة بالمشروع.
7) Build → Rebuild Solution، لازم 1 succeeded, 0 failed. ثم Ctrl+F5 واكتبي 4.
8) انقلي الإجابات النظرية من ملف Written Answers إلى مربعات ورقة الدكتور؛ أضيفي معلوماتك ورابط Git الحقيقي.
9) حسب الورقة، مطلوب commit و push عند التسليم، بالإضافة إلى إجابات السؤال النظري. اتبعي وسيلة التسليم المعتمدة من الدكتور.
ملاحظة: الكود تمت تجربته بـ g++ C++17 على نظام لينكس، وليس داخل جهازك Visual Studio؛ تأكدي من البناء عندك.

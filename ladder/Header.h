/// Перечисление с кодами ошибок
enum class ErrorCode {
	/// Ошибок нет
	NoError,
	/// Не удалось найти/открыть входной файл
	IncorrectInputFile,
	/// Данные в файле не являются натуральным числом
	IncorrectInputData,
	/// Число выходит за пределы диапазона
	IncorrectNumber,
	/// Не удалось найти/открыть выходной файл
	IncorrectOutputFile
};


/*!
Переводит массив символов в число
\param[in] string Массив символов
\return Если не удалось преобразовать строку, то возвращает -1, иначе - целое не отрицательное число
*/
int charToInt(char* string);

/*!
Считывает число из файла
\param[in] path Путь к файлу, из которого нужно считать число
\return Если не удалось открыть файл, то вернётся число -2, иначе если не удаётся считать значение, вернётся -1, иначе - само число
*/
int readNumberFromFile(char* path);

/*!
Подсчитывает кол-во лесенок
\param[in] prev_level Кол-во коробок на предыдущей строке
\param[in] number Кол-во оставшихся коробок
\return Число лесенок
*/
int calculateLaddersNumber(int prev_level, int number);

/*!
Записывает число в файл
\param[in] result Число - кол-во лесенок
\param[in] path Путь к файлу, в который нужно записать ответ
\return Код ошибки
*/
ErrorCode writeResultToFile(int result, char* path);

/*!
Проверяет число на корректность
\param[in] number Число
\return Код ошибки
*/
ErrorCode isNumberCorrect(int number);

#ifndef AIRPORT_CFLIGHTCOMPEXCEPTION_H
#define AIRPORT_CFLIGHTCOMPEXCEPTION_H
#include <iostream>

class CFlightCompException
{
public:
	virtual void show() const = 0;
	virtual ~CFlightCompException() = default;
};

class CCompStringException : public CFlightCompException
{
	std::string message;
	public:
		CCompStringException(const std::string& message) : message(message) {}
		void show() const override
		{
			std::cout << message << std::endl;
		}
};

class CCompLimitException : public CFlightCompException
{
	int limit;
	public:
		CCompLimitException(int limit) : limit(limit) {}
		void show() const override
		{
			std::cout << "Index Out of bounds exception: " << limit << std::endl;
		}
};

class CCompFileException : public CFlightCompException
{
	std::string fileName;
	public:
		CCompFileException(const std::string& fileName) : fileName(fileName) {}
		void show() const override
		{
			std::cout << "File not found: " << fileName << std::endl;
		}
};

#endif 
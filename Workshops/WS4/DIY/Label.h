// Workshop 4 DIY
// Name: Soham Thaker
// SID: 011-748-159
//Email: sdthaker1@myseneca.ca
//Date of Completion: 2021/02/07
//The below code is my own code and I have not taken any help in order to complete this workshop.

#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H

namespace sdds {

	class Label {
		char* m_text = nullptr;
		char m_frame[9] = { '\0' }; 
		bool m_empty = true;
		void setToDefault(const char* = { "+-+|+-+|" });
		void setText(const char* Cstr);
	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();
		void readLabel();
		std::ostream& printLabel() const;
	};
}

#endif
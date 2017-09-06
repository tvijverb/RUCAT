#include "importmzdata.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <iostream>
#include<algorithm>
#include<iterator>

#include <QXmlStreamReader>
#include <QtCore>
#include <QtWidgets>

GCData* importmzData(const QString current)  {
    // Create new GCData variable to fill with shiny new data
	GCData * data = new GCData();
	MSData * mymsdata = new MSData();
	std::vector<Scan*> myscans;
    std::ifstream fs;

    // Some arbitrary conversion to read file line by line
    char tab2[4096];
    char *next_token1 = NULL;
    QByteArray ba = current.toLatin1();
    const char *c_str2 = ba.data();
    char *strcount = ba.data();
    bool inscan = 0;
    std::string str;
    std::string::size_type n;

    // Open filestream on QString current which was passed to this function
    fs.open(c_str2, std::fstream::in | std::fstream::out | std::fstream::app);

    // new lines will be skipped unless we stop it from happening:
    fs.unsetf(std::ios_base::skipws);

    // count the newlines with an algorithm specialized for counting:
    unsigned line_count = std::count(
        std::istream_iterator<char>(fs),
        std::istream_iterator<char>(),
        '\n');
    // Loop over entire .mzXML file line by line
    // Content pushed to var file_contents

    // Reset iostream to beginning of the file
    fs.clear() ;
    fs.seekg(0, std::ios::beg) ;

    int current_line = 0;
    while (std::getline(fs, str))
    {
        // mzXML schema
        n = str.find("xsi:schemaLocation=");
        if (n != std::string::npos)
        {
            strcpy(tab2, str.c_str());
            char* tab1 = strtok(tab2, "\"");
            tab1 = strtok(NULL, "\"");
			data->setXML(std::string(tab1));
        }

        // n MS scans
        n = str.find("scanCount=");
        if (n != std::string::npos)
        {
            strcpy(tab2, str.c_str());
            char* tab1 = strtok(tab2, "\"");
            tab1 = strtok(NULL, "\"");
        }

        // GC start time
        n = str.find("startTime=");
        if (n != std::string::npos)
        {
            strcpy(tab2, str.c_str());
            char* tab1 = strtok(tab2, "\"");
            tab1 = strtok(NULL, "\"");
            data->setStartTime(std::string(tab1));
        }

        // GC end time
        n = str.find("endTime=");
        if (n != std::string::npos)
        {
            strcpy(tab2, str.c_str());
            char* tab1 = strtok(tab2, "\"");
            tab1 = strtok(NULL, "\"");
            data->setEndTime(std::string(tab1));
        }

        // filename
        n = str.find("fileName=");
        if (n != std::string::npos)
        {
            strcpy(tab2, str.c_str());
            char* tab1 = strtok(tab2, "\"");
            tab1 = strtok(NULL, "\"");
            data->setName(std::string(tab1));
        }

        // filetype
        n = str.find("fileType=");
        if (n != std::string::npos)
        {
            strcpy(tab2, str.c_str());
            char* tab1 = strtok(tab2, "\"");
            tab1 = strtok(NULL, "\"");
            data->setFileType(std::string(tab1));
        }

        // sha1
        n = str.find("fileSha1=");
        if (n != std::string::npos)
        {
            strcpy(tab2, str.c_str());
            char* tab1 = strtok(tab2, "\"");
            tab1 = strtok(NULL, "\"");
            data->setSHA(std::string(tab1));
        }

        // manufacturer
        n = str.find("category=\"msManufacturer\" value=");
        if (n != std::string::npos)
        {
            strcpy(tab2, str.c_str());
            char* tab1 = strtok(tab2, "\"");
            tab1 = strtok(NULL, "\"");
            tab1 = strtok(NULL, "\"");
            tab1 = strtok(NULL, "\"");
            data->setManufacturer(std::string(tab1));
        }

        // model
        n = str.find("category=\"msModel\" value=");
        if (n != std::string::npos)
        {
            strcpy(tab2, str.c_str());
            char* tab1 = strtok(tab2, "\"");
            tab1 = strtok(NULL, "\"");
            tab1 = strtok(NULL, "\"");
            tab1 = strtok(NULL, "\"");
            data->setModel(std::string(tab1));
        }

        // ionisation
        n = str.find("category=\"msIonisation\" value=");
        if (n != std::string::npos)
        {
            strcpy(tab2, str.c_str());
            char* tab1 = strtok(tab2, "\"");
            tab1 = strtok(NULL, "\"");
            tab1 = strtok(NULL, "\"");
            tab1 = strtok(NULL, "\"");
            data->setIonisation(std::string(tab1));
        }

        // ms_type
        n = str.find("category=\"msMassAnalyzer\" value=");
        if (n != std::string::npos)
        {
            strcpy(tab2, str.c_str());
            char* tab1 = strtok(tab2, "\"");
            tab1 = strtok(NULL, "\"");
            tab1 = strtok(NULL, "\"");
            tab1 = strtok(NULL, "\"");
            mymsdata->setMSType(std::string(tab1));
        }

        // ms_detector
        n = str.find("category=\"msDetector\" value=");
        if (n != std::string::npos)
        {
            strcpy(tab2, str.c_str());
            char* tab1 = strtok(tab2, "\"");
            tab1 = strtok(NULL, "\"");
            tab1 = strtok(NULL, "\"");
            tab1 = strtok(NULL, "\"");
            mymsdata->setMSDetector(std::string(tab1));
        }
        // Read scans
        n = str.find("scan num=");
        if ((n != std::string::npos) || inscan == 1)
        {
            // Find scan number and keep in this loop
            if(inscan == 0) {
                inscan = 1;
                strcpy(tab2, str.c_str());
                char* tab1 = strtok(tab2, "\"");
                tab1 = strtok(NULL, "\"");
				myscans.push_back(new Scan());
                try {
                    //data.scan_n.push_back(std::stoi(tab1));
                }
                catch (std::exception const &e) {
                    //cout << "int conversion failed, exiting" << endl;
                    // This could not be parsed into a number so an exception is thrown.
                    // atoi() would return 0, which is less helpful if it could be a valid value.
                }
            }

            // MS level
            n = str.find("msLevel=");
            if (n != std::string::npos)
            {
                strcpy(tab2, str.c_str());
                char* tab1 = strtok(tab2, "\"");
                tab1 = strtok(NULL, "\"");
				myscans.back()->scan_mslvl = std::stoi(tab1);
            }

            // Peak count
            n = str.find("peaksCount=");
            if (n != std::string::npos)
            {
                strcpy(tab2, str.c_str());
                char* tab1 = strtok(tab2, "\"");
                tab1 = strtok(NULL, "\"");
                myscans.back()->scan_peakc = std::stoi(tab1);
            }

            // retentiontime
            n = str.find("retentionTime=");
            if (n != std::string::npos)
            {
                strcpy(tab2, str.c_str());
                char* tab1 = strtok(tab2, "\"");
                tab1 = strtok(NULL, "\"");
                data->addScanRT_s(tab1);
                data->addScanRT_d(std::stod(data->getScanRT_s().back()));
                data->addScanRT_i(data->getScanRT_d().back()*1000);
            }

            // lowMz
            n = str.find("lowMz=");
            if (n != std::string::npos)
            {
                strcpy(tab2, str.c_str());
                char* tab1 = strtok(tab2, "\"");
                tab1 = strtok(NULL, "\"");
				myscans.back()->scan_lowmz = std::stod(tab1);
            }

            // highMz
            n = str.find("highMz=");
            if (n != std::string::npos)
            {
                strcpy(tab2, str.c_str());
                char* tab1 = strtok(tab2, "\"");
                tab1 = strtok(NULL, "\"");
				myscans.back()->scan_highmz = std::stod(tab1);
            }

            // basepeakMz
            n = str.find("basePeakMz=");
            if (n != std::string::npos)
            {
                strcpy(tab2, str.c_str());
                char* tab1 = strtok(tab2, "\"");
                tab1 = strtok(NULL, "\"");
				myscans.back()->scan_basepeakmz = std::stod(tab1);
            }

            // basepeak intensity
            n = str.find("basePeakIntensity=");
            if (n != std::string::npos)
            {
                strcpy(tab2, str.c_str());
                char* tab1 = strtok(tab2, "\"");
                tab1 = strtok(NULL, "\"");
				myscans.back()->scan_basepeakintensity = std::stod(tab1);
            }

            // tic
            n = str.find("totIonCurrent=");
            if (n != std::string::npos)
            {
                strcpy(tab2, str.c_str());
                char* tab1 = strtok(tab2, "\"");
                tab1 = strtok(NULL, "\"");
                data->ScanAddTIC(std::stoi(tab1));
                data->ScanAddTIC_d(std::stod(tab1));
            }

            // MS peaks
            n = str.find("pairOrder=\"m/z-int\">");
            if (n != std::string::npos)
            {
                strcpy(tab2, str.c_str());
                char* tab1 = strtok(tab2, "\"");
                tab1 = strtok(NULL, "\"");
                tab1 = strtok(NULL, "\"");
				myscans.back()->scan_mspeaks = tab1;
				myscans.back()->scan_mspeaks.erase(0, 1);
                int sz = myscans.back()->scan_mspeaks.size();
				myscans.back()->scan_mspeaks.erase(sz - 8);
                std::string bAr = data->base64_decode(myscans.back()->scan_mspeaks);
                QByteArray mbyteArray(bAr.c_str(), bAr.length());
                uint32_t * uintBuf = (uint32_t *) mbyteArray.data();
                for( int size = mbyteArray.size() / (2 * sizeof(uint32_t)); size; size-- )
                {
                    float f;
                    float a;
                    * (uint32_t *) &f = ntohl( *uintBuf++ );
					myscans.back()->x.push_back(f);
                    * (uint32_t *) &a = ntohl( *uintBuf++ );
					myscans.back()->y.push_back(a);
                }
                inscan = 0;
				mymsdata->addScan(myscans.back());
            }

            // Remove empty peaks
            n = str.find("byteOrder=\"network\" pairOrder=\"m/z-int\" xsi:nil=\"1\"");
            if (n != std::string::npos)
            {
				//myscans.back()->empty();
				mymsdata->addScan(myscans.back());

                inscan = 0;
            }
        }
        current_line++;
    }
    // Push msdata to gcdata class
        data->setMSData(mymsdata);
    data->setLinePoints(data->getScanRT_i(),data->getScanTIC());
    fs.close();
    return data;
}

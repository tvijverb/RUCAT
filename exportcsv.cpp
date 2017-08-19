#include "exportcsv.h"

exportcsv::exportcsv(QObject *parent)
    : QObject(parent)
{
}

void exportcsv::export_single_csv(QTreeWidget * treewidget,std::vector<GCData*> data)
{
    int selectedTIC;
    QModelIndexList indexlist = treewidget->selectionModel()->selectedIndexes();
    foreach(const QModelIndex &index,treewidget->selectionModel()->selectedIndexes())
    {
        QModelIndex parent = index.parent();

        if(!parent.isValid() && index.data(Qt::DisplayRole).toString() != "No data loaded in RUCAT")
        {
            qDebug() << "Entering single csv export";
			//selectedTIC = 1;
			selectedTIC = index.row() - 1;

            GCData * mydata = data.at(selectedTIC);
			std::vector<int> scanrt = mydata->getScanRT_i();
            std::vector<int> scantic = mydata->getScanTIC();

			QString csvfilename = (index.data(Qt::DisplayRole).toString());
			std::size_t found = csvfilename.toStdString().find_last_of("/\\");
			
			std::ofstream csvfile;
			csvfile.open(csvfilename.toStdString().substr(found + 1) + ".csv");
			qDebug() << QString::fromStdString(csvfilename.toStdString().substr(found + 1) + ".csv");
			//csvfile.open("1.csv");
            csvfile << (csvfilename.toStdString()) << ",";
			for (std::vector<int>::size_type i = 0; i != scanrt.size(); i++)
            {
                csvfile << scanrt[i] << "," << scantic[i] << ",";
            }
			csvfile.seekp(-1, std::ios_base::end);
            csvfile << " ";
            csvfile.close();
        }
    }
}

void exportcsv::TICCSVALL_Files(QTreeWidget * treewidget,std::vector<GCData*> data)
{
    qDebug() << "Entering all csv export";
    for (std::vector<int>::size_type i = 0; i != data.size(); i++) {
        GCData * mydata = data.at(i);
        std::vector<int> scanrt = mydata->getScanRT_i();
        std::vector<int> scantic = mydata->getScanTIC();

        QString csvfilename = QString::fromStdString(mydata->getName());
        std::size_t found = csvfilename.toStdString().find_last_of("/\\");

        std::ofstream csvfile;
        csvfile.open(csvfilename.toStdString().substr(found + 1) + ".csv");
        qDebug() << QString::fromStdString(csvfilename.toStdString().substr(found + 1) + ".csv");

        csvfile << (csvfilename.toStdString()) << ",";
        for (std::vector<int>::size_type i = 0; i != scanrt.size(); i++)
        {
            csvfile << scanrt[i] << "," << scantic[i] << ",";
        }
        csvfile.seekp(-1, std::ios_base::end);
        csvfile << " ";
        csvfile.close();
    }
}

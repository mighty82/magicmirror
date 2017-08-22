#ifndef __WEATHERDATA_H__
#define __WEATHERDATA_H__

#include <QtCore/QtCore>
#include <QtNetwork/QtNetwork>

class WeatherData : public QObject
{
	Q_OBJECT
public:
	WeatherData(QObject *parent = 0);
	virtual ~WeatherData();

	void addZip(QString);
	void addAppID(QString);

signals:
	void currentConditions(QMap<QString,QString>);
	void localForecast(QString);
	void finished();
	void error(QString);

public slots:
	void process();
	void forecastReplyFinished(QNetworkReply*);
	void currentReplyFinished(QNetworkReply*);

private:
	void processCurrentWeather();
	void processForecast();

	QNetworkAccessManager *m_forecast;
	QNetworkAccessManager *m_current;
	QString m_appID;
	QString m_zip;
};

#endif
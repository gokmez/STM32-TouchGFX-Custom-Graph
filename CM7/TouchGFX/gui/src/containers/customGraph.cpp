#include <gui/containers/customGraph.hpp>

customGraph::customGraph()
{

}

void customGraph::initialize()
{
    customGraphBase::initialize();

    firstDataTime = 1681492804;			// 1681492804 --> 14 April 2023 17:20			//firstDataTime = time(NULL);
    convert_timeStampToDateTime(&firstDataTime, &firstDataTime_tm);

    addPoint(firstDataTime, float(1.0));
//	addPoint(firstDataTime + 1200, float(1.3));
//	addPoint(firstDataTime + 1200, float(1.8));
//	addPoint(firstDataTime + 2400, float(2.0));
//	addPoint(firstDataTime + 54000, float(333.5));
//	addPoint(firstDataTime + 55000, float(353.5));
//	addPoint(firstDataTime + 56000, float(343.5));
//	addPoint(firstDataTime + 57000, float(348.5));
//	addPoint(firstDataTime + 58000, float(379.5));
//	addPoint(firstDataTime + 72000, float(40000.5));

	setTimeRange(24);
	setYAxisLabel("Voltage");
}


void customGraph::addPoint(time_t x, float y)
{
	struct tm x_tm;
	float x_axisVal;

	if(firstDataTaken == 0)
	{
		firstDataTaken = 1;
		firstDataTime = x;
		convert_timeStampToDateTime(&firstDataTime, &firstDataTime_tm);
		customGraphBase::graph1.addDataPoint(float(0.0), y);
	}
	else
	{
		convert_timeStampToDateTime(&x, &x_tm);
		if(x_tm.tm_year == firstDataTime_tm.tm_year && x_tm.tm_mon == firstDataTime_tm.tm_mon && (x_tm.tm_mday - firstDataTime_tm.tm_mday) < 2)
		{
			x_axisVal = ((x_tm.tm_mday - firstDataTime_tm.tm_mday)*24*60) + ((x_tm.tm_hour - firstDataTime_tm.tm_hour)*60) + (x_tm.tm_min - firstDataTime_tm.tm_min);
			customGraphBase::graph1.addDataPoint(float(x_axisVal), y);
		}
	}
}


void customGraph::setMaxPoint(int maxPoint)
{
	customGraphMaxPoint = maxPoint;
}


void customGraph::setTimeRange(int hours)
{

	if(hours == 1 || hours ==8 || hours == 24)
	{
		customGraphTimeRange = hours;
		customGraphInterval = (hours*60)/numberofGrid;
		customGraphBase::graph1.setGraphRangeX(0, hours*60);
		//customGraphBase::graph1MajorXAxisLabel.setInterval(customGraphInterval);
		customGraphBase::graph1MajorXAxisGrid.setInterval(customGraphInterval);
		customGraphBase::graph1.setGraphRangeYAutoScaled(true,1);
		customGraphBase::graph1MajorYAxisLabel.setInterval((graph1.getGraphRangeYMaxAsInt() - graph1.getGraphRangeYMinAsInt())/float(numberofGrid));
		customGraphBase::graph1MajorYAxisGrid.setInterval((graph1.getGraphRangeYMaxAsInt() - graph1.getGraphRangeYMinAsInt())/float(numberofGrid));

		timeLabel1_time = firstDataTime + customGraphInterval*60;
		convert_timeStampToDateTime(&timeLabel1_time, &timeLabel1_time_tm);

		timeLabel2_time = timeLabel1_time + customGraphInterval*60;
		convert_timeStampToDateTime(&timeLabel2_time, &timeLabel2_time_tm);

		timeLabel3_time = timeLabel2_time + customGraphInterval*60;
		convert_timeStampToDateTime(&timeLabel3_time, &timeLabel3_time_tm);

		timeLabel4_time = timeLabel3_time + customGraphInterval*60;
		convert_timeStampToDateTime(&timeLabel4_time, &timeLabel4_time_tm);

		Unicode::snprintf(dateLabelBuffer, 10, "%02d-%02d-%02d",firstDataTime_tm.tm_mday, firstDataTime_tm.tm_mon, firstDataTime_tm.tm_year-100);
		dateLabel.setWildcard(dateLabelBuffer);
		dateLabel.invalidate();
		dateLabel.resizeToCurrentText();
		dateLabel.invalidate();

		updateTimeLabel(&timeLabel1, timeLabel1Buffer, &timeLabel1_time_tm);
		updateTimeLabel(&timeLabel2, timeLabel2Buffer, &timeLabel2_time_tm);
		updateTimeLabel(&timeLabel3, timeLabel3Buffer, &timeLabel3_time_tm);
		updateTimeLabel(&timeLabel4, timeLabel4Buffer, &timeLabel4_time_tm);

		customGraphBase::timeLabel1.setX(graph1.getX() + (graph1.getGraphAreaWidth()*1/numberofGrid) + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - (timeLabel1.getTextWidth()/2) + 1);
		customGraphBase::timeLabel2.setX(graph1.getX() + (graph1.getGraphAreaWidth()*2/numberofGrid) + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - (timeLabel2.getTextWidth()/2) + 1);
		customGraphBase::timeLabel3.setX(graph1.getX() + (graph1.getGraphAreaWidth()*3/numberofGrid) + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - (timeLabel3.getTextWidth()/2) + 1);
		customGraphBase::timeLabel4.setX(graph1.getX() + (graph1.getGraphAreaWidth()*4/numberofGrid) + graph1.getGraphAreaMarginLeft() - graph1.getGraphAreaMarginRight() - (timeLabel4.getTextWidth()/2) + 1);

		scrollCounter = 0;
	}
}


void customGraph::setYAxisLabel(const char* name){
	Unicode::snprintf(y_axisNameBuffer, 10, name);
	y_axisName.setWildcard(y_axisNameBuffer);
	y_axisName.invalidate();
	y_axisName.resizeToCurrentText();
	y_axisName.invalidate();

	y_axisName.setX(graph1.getX() + graph1.getGraphAreaMarginLeft() - (y_axisName.getTextWidth()/2));
}


void customGraph::setLineColor(uint32_t colorCode)
{
	graph1Line1Painter.setColor(touchgfx::Color::getColorFromRGB((colorCode&0x00FF0000) >> 16, (colorCode&0x0000FF00) >> 8, colorCode&0x000000FF));
}

void customGraph::clearAllData()
{
	graph1.clear();
}


void customGraph::cleanUp()
{
	this->setVisible(false);
	this->removeAll();
}

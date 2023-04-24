/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef CUSTOMGRAPHBASE_HPP
#define CUSTOMGRAPHBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/graph/Graph.hpp>
#include <touchgfx/widgets/graph/GraphElements.hpp>
#include <touchgfx/widgets/graph/GraphLabels.hpp>
#include <touchgfx/widgets/canvas/PainterRGB888.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class customGraphBase : public touchgfx::Container
{
public:
    customGraphBase();
    virtual ~customGraphBase();
    virtual void initialize();

    /*
     * Virtual Action Handlers
     */
    virtual void graph1Dragged(AbstractDataGraph::GraphDragEvent value)
    {
        // Override and implement this function in customGraph
    }
    virtual void graph1clicked(AbstractDataGraph::GraphClickEvent value)
    {
        // Override and implement this function in customGraph
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box box1;
    touchgfx::Graph<500> graph1;
    touchgfx::GraphElementGridX graph1MajorXAxisGrid;
    touchgfx::GraphElementGridY graph1MajorYAxisGrid;
    touchgfx::GraphLabelsY graph1MajorYAxisLabel;
    touchgfx::GraphElementLine graph1Line1;
    touchgfx::PainterRGB888 graph1Line1Painter;
    touchgfx::TextAreaWithOneWildcard debugText;
    touchgfx::TextAreaWithOneWildcard timeLabel4;
    touchgfx::TextAreaWithOneWildcard timeLabel3;
    touchgfx::TextAreaWithOneWildcard timeLabel2;
    touchgfx::TextAreaWithOneWildcard timeLabel1;
    touchgfx::TextAreaWithOneWildcard dateLabel;
    touchgfx::TextAreaWithOneWildcard y_axisName;

    /*
     * Wildcard Buffers
     */
    static const uint16_t DEBUGTEXT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar debugTextBuffer[DEBUGTEXT_SIZE];
    static const uint16_t TIMELABEL4_SIZE = 10;
    touchgfx::Unicode::UnicodeChar timeLabel4Buffer[TIMELABEL4_SIZE];
    static const uint16_t TIMELABEL3_SIZE = 10;
    touchgfx::Unicode::UnicodeChar timeLabel3Buffer[TIMELABEL3_SIZE];
    static const uint16_t TIMELABEL2_SIZE = 10;
    touchgfx::Unicode::UnicodeChar timeLabel2Buffer[TIMELABEL2_SIZE];
    static const uint16_t TIMELABEL1_SIZE = 10;
    touchgfx::Unicode::UnicodeChar timeLabel1Buffer[TIMELABEL1_SIZE];
    static const uint16_t DATELABEL_SIZE = 10;
    touchgfx::Unicode::UnicodeChar dateLabelBuffer[DATELABEL_SIZE];
    static const uint16_t Y_AXISNAME_SIZE = 10;
    touchgfx::Unicode::UnicodeChar y_axisNameBuffer[Y_AXISNAME_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<customGraphBase, const touchgfx::AbstractDataGraph&, const touchgfx::AbstractDataGraph::GraphDragEvent&> graphDraggedCallback;
    touchgfx::Callback<customGraphBase, const touchgfx::AbstractDataGraph&, const touchgfx::AbstractDataGraph::GraphClickEvent&> graphClickedCallback;

    /*
     * Callback Handler Declarations
     */
    void graphDraggedCallbackHandler(const touchgfx::AbstractDataGraph& src, const touchgfx::AbstractDataGraph::GraphDragEvent& value);
    void graphClickedCallbackHandler(const touchgfx::AbstractDataGraph& src, const touchgfx::AbstractDataGraph::GraphClickEvent& value);

};

#endif // CUSTOMGRAPHBASE_HPP

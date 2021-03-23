#include "Operations/IOperation.h"
#include "Operations/Operation_DigitalPinRecord.h"
#include "ReluctorResult.h"
#include "Packed.h"
#include "Interpolation.h"

#ifndef OPERATION_RELUCTORGM24X_H
#define OPERATION_RELUCTORGM24X_H
namespace OperationArchitecture
{
	class Operation_ReluctorGM24x : public IOperation<ReluctorResult, Record*, uint32_t>
	{
	protected:
		EmbeddedIOServices::ITimerService *_timerService;
	public:		
        Operation_ReluctorGM24x(EmbeddedIOServices::ITimerService *);

		ReluctorResult Execute(Record *, uint32_t) override;
		bool IsLongPulse(Record *, uint8_t frame);

		static IOperationBase *Create(const EmbeddedIOServices::EmbeddedIOServiceCollection *embeddedIOServiceCollection, const void *config, unsigned int &sizeOut);
	};
}
#endif